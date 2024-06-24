#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char* av[]) {
	if (ac < 2)
		throw std::logic_error("Error: No numbers provided");
	makeOriginContainer(ac, av);
	makeJacobsthal();
}

PmergeMe::~PmergeMe() {
}

bool PmergeMe::isNumber(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (std::isdigit(*it) == 0)
            return false;
    }
    return true;
}

void PmergeMe::makeOriginContainer(int ac, char **av) {
    std::stringstream ss;

    for (int i = 1; i < ac; ++i) {
        ss << av[i] << " ";
    }

    std::string tmp;
    while (ss >> tmp) {
		if (!isNumber(tmp))
			throw std::logic_error("Error: You can only put positive numbers.");
		int num;
		ss >> num;
		if (num < 0)
			throw std::logic_error("Error: You can only put positive numbers.");
		this->v_.push_back(num);
		this->dq_.push_back(num);
	}
}

void PmergeMe::makeJacobsthal() {
    this->jacob_.reserve(this->v_.size());

    for (size_t i = 2; ; ++i) {
        long long tmp = (std::pow(2, i) - std::pow(-1, i)) / 3;
        jacob_.push_back(tmp);
        if (tmp > static_cast<long long>(this->v_.size())) {
            break;
        }
    }
}

void PmergeMe::run() {
	std::cout << "============================ [RESULT] ============================" << std::endl;
	std::cout << "[before] : ";
	for(size_t i = 0; i < this->v_.size(); i++)
		std::cout << this->v_[i] << " ";
	std::cout << std::endl; std::cout << std::endl;
	
	std::clock_t start = std::clock();
	this->mergeInsertionSort(this->v_);
	std::clock_t end = std::clock();
	double v_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	
	start = std::clock();
	this->mergeInsertionSort(this->dq_);
	end = std::clock();
	double dq_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << "[after]: ";
	for(size_t i = 0; i < this->v_.size(); i++)
		std::cout << this->v_[i] << " ";
	std::cout << std::endl; std::cout << std::endl;
	
	std::cout << "Time to process a range of " << this->v_.size() << " elements with std::[vector] : " << v_time << " us" << std::endl;
//	std::cout << "Is sorted: " << (std::is_sorted(this->v_.begin(), this->v_.end()) ? "True" : "False");
	std::cout << std::endl; std::cout << std::endl;
	
	std::cout << "Time to process a range of " << this->dq_.size() << " elements with std::[deque] : " << dq_time << " us" << std::endl;
//	std::cout << "Is sorted: " << (std::is_sorted(this->dq_.begin(), this->dq_.end()) ? "True" : "False") << std::endl;
}

void PmergeMe::mergeInsertionSort(std::vector<int> &v) {
	if (v.size() == 1)
		return;
	
	std::vector<int> main_chain;
	std::vector<int> pending;
	std::vector< std::pair<int, int> > pairs;
 
	for (size_t i = 0; i < v.size(); i += 2) {
		if (i + 1 < v.size()) {
			if (v[i] > v[i + 1]) {
				main_chain.push_back(v[i]);
				pending.push_back(v[i + 1]);
				pairs.push_back(std::make_pair(v[i], v[i + 1]));
			} else {
				main_chain.push_back(v[i + 1]);
				pending.push_back(v[i]);
				pairs.push_back(std::make_pair(v[i + 1], v[i]));
			}
		}
	}
	
	if (v.size() % 2 == 1)
		pending.push_back(v.back());
	
	this->mergeInsertionSort(main_chain);
	
	for (size_t i = 0; i < main_chain.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j)
			if (main_chain[i] == pairs[j].first) {
				pending[i] = pairs[j].second;
				break;
			}
	}
	
	std::vector<int> sorted_v(main_chain);
	sorted_v.insert(sorted_v.begin(), pending.front());
	
	for (size_t jacob_idx =1; jacob_idx < this->jacob_.size(); ++jacob_idx) {
		int curr = std::min(static_cast<size_t>(this->jacob_[jacob_idx]), pending.size());
		int prev = this->jacob_[jacob_idx - 1];
		for (int idx = curr; idx > prev; --idx) {
			binaryInsertion(sorted_v, sorted_v.size(), pending[idx - 1]);
		}
	}
	v = sorted_v;
}

void PmergeMe::mergeInsertionSort(std::deque<int> &dq) {
	if (dq.size() == 1)
		return;
	
	std::deque<int> main_chain;
	std::deque<int> pending;
	std::deque< std::pair<int, int> > pairs;
 
	for (size_t i = 0; i < dq.size(); i += 2) {
		if (i + 1 < dq.size()) {
			if (dq[i] > dq[i + 1]) {
				main_chain.push_back(dq[i]);
				pending.push_back(dq[i + 1]);
				pairs.push_back(std::make_pair(dq[i], dq[i + 1]));
			} else {
				main_chain.push_back(dq[i + 1]);
				pending.push_back(dq[i]);
				pairs.push_back(std::make_pair(dq[i + 1], dq[i]));
			}
		}
	}
	
	if (dq.size() % 2 == 1)
		pending.push_back(dq.back());
	
	this->mergeInsertionSort(main_chain);
	
	for (size_t i = 0; i < main_chain.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j)
			if (main_chain[i] == pairs[j].first) {
				pending[i] = pairs[j].second;
				break;
			}
	}
	
	std::deque<int> sorted_dq(main_chain);
	sorted_dq.insert(sorted_dq.begin(), pending.front());
	
	for (size_t jacob_idx =1; jacob_idx < this->jacob_.size(); ++jacob_idx) {
		int curr = std::min(static_cast<size_t>(this->jacob_[jacob_idx]), pending.size());
		int prev = this->jacob_[jacob_idx - 1];
		for (int idx = curr; idx > prev; --idx) {
			binaryInsertion(sorted_dq, sorted_dq.size(), pending[idx - 1]);
		}
	}
	dq = sorted_dq;
}

void PmergeMe::binaryInsertion(std::vector<int> &v, size_t end, int insert_value) {
	size_t start = 0;
	
	while (start < end) {
		size_t mid = (start + end) / 2;
		if (v[mid] <= insert_value)
			start = mid + 1;
		else
			end = mid;
	}
	v.insert(v.begin() + start, insert_value);
}

void PmergeMe::binaryInsertion(std::deque<int> &dq, size_t end, int insert_value) {
	size_t start = 0;
	
	while (start < end) {
		size_t mid = (start + end) / 2;
		if (dq[mid] <= insert_value)
			start = mid + 1;
		else
			end = mid;
	}
	dq.insert(dq.begin() + start, insert_value);
}