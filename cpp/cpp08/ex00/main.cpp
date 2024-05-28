#include "easyfind.hpp"
#include <vector>

int main() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	try {
		if (easyfind(v, 3) != v.end()) {
			std::cout << *easyfind(v, 3) << std::endl;
		} else {
			throw std::logic_error("Value not found");
		}
		if (easyfind(v, 6) != v.end()) {
			std::cout << *easyfind(v, 6) << std::endl;
		} else {
			throw std::logic_error("Value not found");
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}