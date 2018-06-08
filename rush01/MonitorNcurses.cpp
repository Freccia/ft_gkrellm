/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorNcurses.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:48:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 16:51:44 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorNcurses.hpp"
#include "OSModule.hpp"
#include <iostream>
#include <signal.h>

MonitorNcurses::MonitorNcurses(void) :
_winX(COLS), _winY(LINES),
_ch(0), _beginTime(clock()), _lastDisplay(0)
{
	initscr();
	if (LINES < MINWIN_Y || COLS < MINWIN_X)
	{
		endwin();
		std::cerr << "Error : the window is too small." << std::endl;
		exit(1);
	}
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(FALSE);

	setlocale(LC_ALL,"");

	this->_win = stdscr;

	MonitorModule *mod1 = new OSModule(0, 3);
	this->_modules.push_back(mod1);
	this->_totX = 0;
	this->_totY = 3;

	signal(SIGWINCH, &MonitorNcurses::resizeHandler);
};

MonitorNcurses::~MonitorNcurses(void) {
	endwin();
};

void		MonitorNcurses::resizeHandler(int sig) {
	if (sig == SIGWINCH) {
		endwin();
		// RESIZE NOT HANDLED
		std::cerr << "Error : resize window." << std::endl;
		exit(1);
	}
}

void		MonitorNcurses::addModule(std::string type) {
	MonitorModule		*last = this->_modules.back();
	std::vector<int>	lpos = last->getPos();
	std::vector<int>	lsiz = last->getSize();
	std::vector<int>	pos(2);
	pos[Y] = (lpos[Y]);
	pos[X] = (lpos[X] + lsiz[X]);

	if (this->_totX + pos[X] >= WCOLS - 1) {
		pos[Y] += lsiz[Y];
		pos[X] = 0;
		this->_totX = 0;
		this->_totY += pos[Y];
	}
	if (this->_totY + pos[Y] >= WLINES - 1) {
		return;
	}

	if (type == "standard") {
		MonitorModule *mod = new MonitorModule(STDMONITOR_X, STDMONITOR_Y, pos[X], pos[Y]);
		this->_modules.push_back(mod);
		this->_totX += pos[X];
	}
}

void		MonitorNcurses::getKey(void) {
	this->_ch = getch();
	if (this->_ch == 't') {
		this->_modules[0]->writeMe(3, 3, "LOL");
	}
	else if (this->_ch == 'c') {
		this->_modules[0]->deleteMe();
		wclear(this->_win);
		clear();
	}
	else if (this->_ch == '+') {
		this->addModule("standard");
	}
	if (this->_ch == 'W' || this->_ch == 'w') {
		int c = getchar();
		if ((c >= '0' && c <= '9') &&
			(c - '0' >= 0 && c - '0' < static_cast<int>(this->_modules.size())))
			this->_modules[c - '0']->deleteMe();
	}
	std::string str = "LINES: ";
	str.append(std::to_string(WLINES));
	str.append(" Y: ");
	str.append(std::to_string(getmaxx(stdscr)));
	str.append(" COLS: ");
	str.append(std::to_string(WCOLS));
	str.append(" X: ");
	str.append(std::to_string(getmaxy(stdscr)));
	str.append(" tot X: ");
	str.append(std::to_string(this->_totX));
	str.append(" tot Y: ");
	str.append(std::to_string(this->_totY));
	mvprintw(0, 0 , str.c_str());
}

int			MonitorNcurses::getCharacter(void) {
	return this->_ch;
}

void		MonitorNcurses::_displayModule(size_t n) {
	if (n < this->_modules.size()) {
		this->_modules[n]->display();
	}
}

void		MonitorNcurses::refreshWindow(void) {
	if (clock() - this->_lastDisplay < 10000)
		return;
	this->_lastDisplay = clock();
	wrefresh(this->_win);
	for (size_t i=0; i < this->_modules.size(); i++) {
		this->_modules[i]->display();
		this->_modules[i]->refresh();
	}
}

