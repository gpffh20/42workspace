#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: Requires one argument." << std::endl;
		return 1;
	}
	
	try {
		BitcoinExchange btc;
		btc.exchange(av[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	
	return 0;
}