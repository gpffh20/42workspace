#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
  public:
	Array() : array_(NULL), size_(0) {}
	Array(unsigned int n) : array_(new T[n]()), size_(n) {}
	~Array() {
		if (array_ != NULL)
			delete[] array_;
	}
	Array(const Array &src) : array_(new T[src.size_]), size_(src.size_) {
		for (unsigned int i = 0; i < size_; i++)
			array_[i] = src.array_[i];
	}
	Array &operator=(const Array &other) {
		if (this != &other) {
			delete[] array_;
			array_ = new T[other.size_];
			size_ = other.size_;
			for (unsigned int i = 0; i < size_; i++)
				array_[i] = other.array_[i];
		}
		return *this;
	}
	
	T &operator[](unsigned int idx) {
		if (idx >= size_) {
			throw std::exception();
		}
		return array_[idx];
	}
	const T &operator[](unsigned int idx) const {
		if (idx >= size_) {
			throw std::exception();
		}
		return array_[idx];
	}
	
	unsigned int size() const {
		return size_;
	}
  
  private:
	T *array_;
	unsigned int size_;
};

#endif