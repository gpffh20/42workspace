#include "iter.hpp"

template <typename T>
void print(const T& value) {
	std::cout << value << std::endl;
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, print<int>);

	std::string strArray[] = {"Hello", "World", "From", "CPP07", "Ex01"};
	iter(strArray, 5, print<std::string>);

	return 0;
}