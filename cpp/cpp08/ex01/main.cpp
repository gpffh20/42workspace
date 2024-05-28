#include "Span.hpp"
#include <stdexcept>

int main() {
	Span sp = Span(5);
	Span sp1 = Span(100000);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << "====================================\n" << std::endl;
	
	try {
		Span mySpan(10000);
		std::vector<int> randVec;
		
		srand(static_cast<unsigned int>(time(NULL)));
		for (int i = 0; i < 10000; ++i)
			randVec.push_back(rand() % 100000000);
		
		mySpan.addManyNumbers(randVec.begin(), randVec.end());
//		mySpan.print();
		
		std::cout << "shortest distance: " << mySpan.shortestSpan() << std::endl;
		std::cout << "longest distance: " << mySpan.longestSpan() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}