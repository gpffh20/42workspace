#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <climits>

class PmergeMe {
  public:
	PmergeMe(int ac, char** av);
	~PmergeMe();
	
	void run();
	
  private:
	std::vector<int> v_;
	std::vector<long long> jacob_;
	std::deque<int> dq_;
	
	PmergeMe();
	PmergeMe(const PmergeMe& origin);
	PmergeMe& operator=(const PmergeMe& origin);
	
	bool isNumber(const std::string& str);
	void makeOriginContainer(int ac, char* av[]);
	void makeJacobsthal();
	
	void mergeInsertionSort(std::vector<int>& v);
	void mergeInsertionSort(std::deque<int>& dq);
	
	void binaryInsertion(std::vector<int>& v, size_t end, int insert_value);
	void binaryInsertion(std::deque<int>& dq, size_t end, int insert_value);
};

#endif
