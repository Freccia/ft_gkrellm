/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:52:53 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/07 17:13:56 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
private:
public:
	typedef typename std::deque<T>::iterator iterator;

	MutantStack(void): std::stack<T>() {};
	MutantStack(MutantStack const &Cc): std::stack<T>(Cc) {};
	~MutantStack(void){};

	MutantStack &operator=(MutantStack const &Cc) {
		std::stack<T>::operator=(Cc);
		return *this;
	};

	iterator	begin(void) {
		return this->c.begin();
	};
	iterator	end(void) {
		return this->c.end();
	};
};

#endif
