/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 11:26:09 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/12 13:26:21 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(std::string inFileName, std::string outFileName):
_inFileName(inFileName),
_outFileName(outFileName) {
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
	if (_outFileName.empty() == false) {
		_outFile.open(_outFileName.c_str(), std::ifstream::out);
		if (!_outFile) {
			std::cout << "Unable to open file" << std::endl;
			exit(1);
		}
		_fdOut = &_outFile;
	}
	else {
		_fdOut = &std::cout;
	}
	return;
}

Cat::~Cat() {
	if (_inFileName.empty() == false)
		_inFile.close();
	if (_outFileName.empty() == false)
		_outFile.close();
	return;
}

int				Cat::eofBit(void) {
	return _fdIn->eof();
}

void			Cat::writeLine(void) {
	std::cout << "WRITE\n";
	*_fdOut << _line;
	_line = "";
}

void			Cat::write(std::string str) {
	*_fdOut << str;
}

std::string		Cat::read(void) {
	long			size = 16;
	char			buf[size];

	std::cout << "READ\n";
	while (_fdIn->getline(buf, size)) {
		_line.append(buf);
	}
	_line.append(buf);
	std::cout << "ENDREAD\n";
	return _line;
}
