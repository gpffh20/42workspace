#include "Span.hpp"

Span::Span(unsigned int n) {
	max_num_ = n;
}

Span::~Span() {}

Span::Span(const Span &other) : max_num_(other.max_num_), container_(other.container_) {}

Span &Span::operator=(const Span &other) {
	if (this == &other) {
		return *this;
	}
	max_num_ = other.max_num_;
	container_ = other.container_;
	return *this;
}

void Span::addNumber(int number) {
	if (container_.size() >= max_num_) {
		throw std::runtime_error("Container is full");
	}
	container_.push_back(number);
}

int Span::shortestSpan() {
	if (container_.size() <= 1) {
		throw std::runtime_error("Not enough elements to calculate span");
	}
	std::sort(container_.begin(), container_.end());
	int min_diff = INT_MAX;
	for (size_t i = 1; i < container_.size(); i++) {
		min_diff = std::min(min_diff, container_[i] - container_[i - 1]);
	}
	return min_diff;
}

int Span::longestSpan() {
	if (container_.size() <= 1) {
		throw std::runtime_error("Not enough elements to calculate span");
	}
	std::sort(container_.begin(), container_.end());
	return container_.back() - container_.front();
}