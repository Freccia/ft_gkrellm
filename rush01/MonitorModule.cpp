/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:21:19 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 13:41:55 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorModule.hpp"

MonitorModule::MonitorModule(void):
_size(2, 0), // x=0 y=0
_lastDisplay(0)
{
};

MonitorModule::MonitorModule(int x, int y):
_size(2),
_lastDisplay(clock())
{
	this->_size[0] = x;
	this->_size[1] = y;

	this->subWin = subwin(stdscr, this->_size[Y], this->_size[X], 0, 0);
	box(this->subWin, '+', '+');
	//mvwprintw(this->subWin, 4, 4, "+++++++++++++++++++++");
};

MonitorModule::MonitorModule(WINDOW *father, int x, int y):
_size(2),
_lastDisplay(clock())
{
	this->_size[0] = x;
	this->_size[1] = y;

	this->subWin = subwin(father, this->_size[Y], this->_size[X], 0, 0);
	box(this->subWin, '+', '+');
	//mvwprintw(this->subWin, 4, 4, "+++++++++++++++++++++");
};

MonitorModule::MonitorModule(MonitorModule const &Cc) {
	*this = Cc;
}

MonitorModule::~MonitorModule(void) {
};

MonitorModule	&MonitorModule::operator=(MonitorModule const &Cc) {
	if (this->_size.empty() == false) {
		this->_size[0] = Cc._size[0];
		this->_size[1] = Cc._size[1];
	}
	return *this;
}

std::vector<int> MonitorModule::getSize(void) {
	return this->_size;
}

void			MonitorModule::deleteMe(void) {
	werase(this->subWin);
	wclear(this->subWin);
	this->refresh();
}

void			MonitorModule::writeMe(int x, int y, std::string str) {
	if (mvwprintw(this->subWin, y, x, str.c_str()) == ERR)
		mvprintw(y, x, "ERROR");
	this->refresh();
}

void			MonitorModule::refresh(void) {
	static int o = 0;
	mvprintw(0, 32, std::to_string(o++).c_str());
	mvwprintw(this->subWin, 1, 1, std::to_string(o++).c_str());
	wrefresh(this->subWin);
}
