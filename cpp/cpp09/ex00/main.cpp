#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: Requires one argument." << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	btc.exchange(av[1]);
	
	return 0;
}