/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:19 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 16:50:29 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorModule.hpp"
#include <unistd.h>

MonitorModule::MonitorModule(void):
_size(2, 0), // w=0 h=0
_pos(2, 0), // x=0 y=0
_lastDisplay(0)
{
};

MonitorModule::MonitorModule(int width, int height, int x, int y):
_size(2),
_pos(2),
_lastDisplay(clock())
{
	this->_size[X] = width;
	this->_size[Y] = height;
	this->_pos[X] = x;
	this->_pos[Y] = y;
	this->_subWin = newwin(height, width, y, x);
	box(this->_subWin, '|', '-');
};

MonitorModule::MonitorModule(MonitorModule const &Cc) {
	*this = Cc;
}

MonitorModule::~MonitorModule(void) {
};

MonitorModule	&MonitorModule::operator=(MonitorModule const &Cc) {
	if (this->_size.empty() == false) {
		this->_size[X] = Cc._size[X];
		this->_size[Y] = Cc._size[Y];
		this->_pos[X] = Cc._pos[X];
		this->_pos[Y] = Cc._pos[Y];
	}
	return *this;
}

std::vector<int> MonitorModule::getSize(void) {
	return this->_size;
}

std::vector<int> MonitorModule::getPos(void) {
	return this->_pos;
}

void			MonitorModule::deleteMe(void) {
	werase(this->_subWin);
	wclear(this->_subWin);
}

void			MonitorModule::writeMe(int x, int y, std::string str) {
	mvwprintw(this->_subWin, y, x, str.c_str());
}

void			MonitorModule::refresh(void) {
	wrefresh(this->_subWin);
}

void			MonitorModule::display(void) {
};
