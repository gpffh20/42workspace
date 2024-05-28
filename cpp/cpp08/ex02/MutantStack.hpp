#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
  public:
	// 이터레이터 제공
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	
	iterator begin() {
		return this->c.begin();  // c는 std::stack의 protected 멤버
	}
	
	iterator end() {
		return this->c.end();
	}
	
	const_iterator begin() const {
		return this->c.begin();
	}
	
	const_iterator end() const {
		return this->c.end();
	}
};

#endif
