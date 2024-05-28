#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span {
  public:
	Span(unsigned int n);
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &other);
	
	void addNumber(int number);
	int shortestSpan();
	int longestSpan();
	
  private:
	Span();
	
	unsigned int max_num_;
	std::vector<int> container_;
};

#endif
