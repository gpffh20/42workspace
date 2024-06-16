#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void RPN::calculate(const std::string expression) {
    std::istringstream iss(expression);
    std::stack<double> stack;
    std::string token;

    while (iss >> token) {
        if (!processToken(token, stack)) {
            std::cerr << "Error" << std::endl;
            return ;
        }
    }

    if (stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return ;
    }

    std::cout << stack.top() << std::endl;
}

bool RPN::processToken(const std::string &token, std::stack<double> &stack) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
        if (stack.size() < 2) {
            return false;
        }
        double a = stack.top();
        stack.pop();
        double b = stack.top();
        stack.pop();
        switch (token[0]) {
            case '+': stack.push(b + a); break;
            case '-': stack.push(b - a); break;
            case '*': stack.push(b * a); break;
            case '/':
                if (a == 0) {
                    std::cerr << "Error: Division by zero." << std::endl;
                    return 1;
                }
                stack.push(b / a);
                break;
        }
    } else {
        if (!isValidNumber(token)) {
            return false;
        }
        stack.push(stringToDouble(token));
    }
    return true;
}

bool RPN::isValidNumber(const std::string &token) {
    try {
        stringToDouble(token);
        return true;
    } catch (const std::runtime_error& e) {
        return false;
    }
}

double RPN::stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double value;
    if (!(iss >> value) || !iss.eof()) {
        throw std::runtime_error("Error: Conversion to double failed.");
    }
    return value;
}