#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span {
  public:
	Span(unsigned int n);
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &other);
	
	void addNumber(int number);
	template<typename InputIterator>
	void addManyNumbers(InputIterator begin, InputIterator end) {
		if (std::distance(begin, end) + container_.size() > max_num_) {
			throw std::runtime_error("Container is full");
		}
		container_.insert(container_.end(), begin, end);
	}
	
	void print() const {
		for (std::vector<int>::const_iterator it = container_.begin(); it != container_.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	
	int shortestSpan();
	int longestSpan();
  
  private:
	Span();
	
	unsigned int max_num_;
	std::vector<int> container_;
};

#endif
