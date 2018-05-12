/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:15:59 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 12:04:00 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <fstream>

class Cat {
public:
	Cat(std::string inFileName, std::string outFileName);
	~Cat();
	void			write(std::string str);
	void			writeLine(void);
	std::string		read(void);
	int				eofBit(void);

private:
	std::string		_inFileName;
	std::string		_outFileName;
	std::ifstream	_inFile;
	std::ofstream	_outFile;
	std::istream*	_fdIn;
	std::ostream*	_fdOut;
	std::string		_line;
};

#endif
