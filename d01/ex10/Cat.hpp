/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:15:59 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 14:04:43 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <string>

class Cat {
public:
	Cat(std::string inFileName);
	~Cat();
	void			write(void);
	bool			read(void);
	void			close(void);
	int				setFile(std::string name);

private:
	std::string		_inFileName;
	std::ifstream	_inFile;
	std::istream*	_fdIn;
	std::string		_line;
};

#endif
