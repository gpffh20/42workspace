#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, void (*func)(const F&)) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

#endif
