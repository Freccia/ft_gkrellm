/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:19 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 22:21:59 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorModule.hpp"
#include <unistd.h>
#include <QFrame>

MonitorModule::MonitorModule(void):
_size(2, 0), // w=0 h=0
_pos(2, 0), // x=0 y=0
_lastDisplay(0) {
};

MonitorModule::MonitorModule(int width, int height, int x, int y):
_name("standard"),
_size(2),
_pos(2),
_lastDisplay(clock())
{
	this->_size[C_X] = width;
	this->_size[C_Y] = height;
	this->_pos[C_X] = x;
	this->_pos[C_Y] = y;
	this->_subWin = newwin(height, width, y, x);
}

MonitorModule::MonitorModule(int width, int height, int x, int y, std::string name):
_size(2),
_pos(2),
_lastDisplay(clock())
{
	this->_name = name;
	this->_size[C_X] = width;
	this->_size[C_Y] = height;
	this->_pos[C_X] = x;
	this->_pos[C_Y] = y;
	this->_subWin = newwin(height, width, y, x);
}

MonitorModule::MonitorModule(MonitorModule const &Cc) {
	*this = Cc;
}

MonitorModule::~MonitorModule(void) {
}

MonitorModule	&MonitorModule::operator=(MonitorModule const &Cc) {
	if (this->_size.empty() == false) {
		this->_size[C_X] = Cc._size[C_X];
		this->_size[C_Y] = Cc._size[C_Y];
		this->_pos[C_X] = Cc._pos[C_X];
		this->_pos[C_Y] = Cc._pos[C_Y];
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
	box(this->_subWin, '|', '-');
}


void MonitorModule::displayQT()
{
    return;
}

void MonitorModule::_init()
{
    return;
}

void MonitorModule::displayChart(void)
{
    return;
}
