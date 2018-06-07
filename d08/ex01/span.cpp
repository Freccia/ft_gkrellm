/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:20:46 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/07 16:44:11 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "span.hpp"

intContainer::intContainer(int N): _N(N), _amount(0) {
}

intContainer::intContainer(intContainer const &Cc) {
	*this = Cc;
}

intContainer::~intContainer(void) {
}

intContainer		&intContainer::operator = (intContainer const &Cc) {
	this->_N = Cc._N;
	this->_vec = Cc._vec;
	this->_amount = Cc._amount;
	return *this;
}

void		intContainer::addNumber(int n) {
	if (this->_amount + 1 > this->_N)
		throw intContainer::FullContainer();
	this->_vec.push_back(n);
	++this->_amount;
}

void		intContainer::addRange(
std::vector<int>::const_iterator start,
std::vector<int>::const_iterator end )
{
	int		dist = std::distance(start, end);
	if (this->_amount + dist >= this->_N)
		throw intContainer::FullContainer();
	for (std::vector<int>::const_iterator i = start; i != end; i++) {
		this->_vec.push_back(*i);
		++this->_amount;
	}
}

void		intContainer::addRange(int start, int end)
{
	int		dist = std::abs(start - end);
	if (this->_amount + dist >= this->_N)
		throw intContainer::FullContainer();
	for (int i = start; i < end; i++) {
		this->_vec.push_back(i);
		++this->_amount;
	}
}

unsigned int	intContainer::longestSpan(void) {
	if (this->_N <= 1 || this->_amount <= 1)
		throw intContainer::VoidContainer();
	std::vector<int>::const_iterator	start = this->_vec.begin();
	std::vector<int>::const_iterator	end = this->_vec.end();
	std::vector<int>::const_iterator	prev;
	int		max = std::numeric_limits<int>::min();
	long	tmp;
	for (std::vector<int>::const_iterator i = start + 1; i != end; i++) {
		prev = i - 1;
		tmp = std::labs(*i - *prev);
		if (tmp > static_cast<long>(max))
			max = std::abs(*i - *prev);
	}
	return max;
	/*
	return (*(std::max_element(_vec.begin(), _vec.end())) - *(std::min_element(_vec.begin(), _vec.end())));
	*/
}

unsigned int	intContainer::shortestSpan(void) {
	if (this->_N <= 1 || this->_amount <= 1)
		throw intContainer::VoidContainer();
	std::vector<int>::const_iterator	start = this->_vec.begin();
	std::vector<int>::const_iterator	end = this->_vec.end();
	std::vector<int>::const_iterator	prev;
	unsigned int	min = std::numeric_limits<int>::max();
	unsigned long	tmp;
	for (std::vector<int>::const_iterator i = start + 1; i != end; i++) {
		prev = i - 1;
		tmp = std::labs(*i - *prev);
		if (static_cast<unsigned int>(tmp) < min)
			min = std::abs(*i - *prev);
	}
	//std::sort(tmp.begin(), tmp.end());
	return min;
}
