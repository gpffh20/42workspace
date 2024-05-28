#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	if (container.empty())
		return container.end();
	return std::find(container.begin(), container.end(), value);
}

#endif