/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:26:09 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 14:10:23 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(std::string inFileName):
_inFileName(inFileName) {
	if (_inFileName.empty() == false) {
		_inFile.open(_inFileName.c_str(), std::ifstream::in);
		if (!_inFile) {
			std::cout << "Unable to open file" << std::endl;
			exit(1);
		}
		_fdIn = &_inFile;
	}
	else {
		_fdIn = &std::cin;
	}
	return;
}

Cat::~Cat() {
	if (_inFileName.empty() == false)
		_inFile.close();
	return;
}

void			Cat::close(void) {
	if (_inFileName.empty() == false)
		_inFile.close();
}

int				Cat::setFile(std::string name) {
	_inFileName = name;
	if (_inFileName.empty() == false) {
		_inFile.open(_inFileName.c_str(), std::ifstream::in);
		if (!_inFile) {
			std::cout << "Unable to open file" << std::endl;
			exit(1);
		}
		_fdIn = &_inFile;
	}
	return 0;
}

void			Cat::write(void) {
	if (_line.empty() == false)
		std::cout << _line;
}

bool			Cat::read(void) {
	std::getline(*_fdIn, _line);
	if (_fdIn->eof())
		return false;
	_line.append("\n");
	return true;
}
