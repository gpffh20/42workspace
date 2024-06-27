#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<double> stack;
    std::string token;

    while (iss >> token) {
        if (!processToken(token, stack)) {
			throw std::runtime_error("Error");
        }
    }

    if (stack.size() != 1) {
		throw std::runtime_error("Error");
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
					throw std::runtime_error("Error: Division by zero.");
                }
                stack.push(b / a);
                break;
        }
    } else {
        stack.push(stringToInt(token));
    }
    return true;
}

double RPN::stringToInt(const std::string& str) {
    std::istringstream iss(str);
    int value;
    if (!(iss >> value) || !iss.eof()) {
        throw std::runtime_error("Error");
    }
    return value;
}