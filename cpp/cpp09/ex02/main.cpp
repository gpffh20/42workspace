#include "PmergeMe.hpp"

int main(int ac, char* av[]) {
	try {
		PmergeMe FordJohnson(ac, av);
		
		FordJohnson.run();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
    return 0;
}
