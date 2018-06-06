/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:53:14 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/06 14:43:29 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>

class Array {
private:
	unsigned int	_size;
	T				*_arr;

public:
	Array(): _arr(NULL), _size(0) {};
	Array(unsigned int size): _size(size) {
			this->_arr = (size != 0) ? new T(size) : NULL;
	};
	Array(Array const &Cc) {
		this->_size = Cc._size;
		this->_arr = new T(Cc._size);
		for (unsigned int i=0; i < Cc._size; i++) {
			this->_arr[i] = Cc._arr[i];
		}
	}
	~Array() { delete[] this->_arr; };

	/* MEMBER FUNCTIONS */
	unsigned int		size(void) { return this->_size; };

	/* EXCEPTIONS */
	struct OperatorOutOfRange : public std::exception {
		const char * what () const throw () {
			return "OperatorOutOfRange";
		}
	};

	/* OPERATORS */
	Array	&operator = (Array const &Cc) {
		this->_size = Cc._size;
		this->_arr = new T(Cc._size);
		for (unsigned int i=0; i < Cc._size; i++) {
			this->_arr[i] = Cc._arr[i];
		}
	}

	T		&operator [] (unsigned int k) throw (std::exception) {
		if (k > this->_size || this->_size == 0 || this->_arr == NULL) {
			//throw Array::OperatorOutOfRange();
			throw (std::exception());
		}
		return this->_arr[k];
	}
};

#endif
