/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:11:00 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/07 16:52:13 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span {
private:
	Span(void);

	unsigned int		_N;
	unsigned int		_amount;
	std::vector<int>	_vec;


public:
	Span(int N);
	Span(Span const &Cc);
	~Span(void);
	Span	&operator = (Span const &Cc);

	void			addNumber(int n);
	void			addRange(int start, int end);
	void			addRange(std::vector<int>::const_iterator start,
						std::vector<int>::const_iterator end);
	unsigned int	longestSpan(void);
	unsigned int	shortestSpan(void);

	struct VoidContainer : public std::exception {
		const char * what () const throw () {
			return "VoidContainer";
		}
	};
	struct FullContainer : public std::exception {
		const char * what () const throw () {
			return "FullContainer";
		}
	};

};

#endif
