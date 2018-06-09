/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorNcurses.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:48:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/09 14:43:26 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorNcurses.hpp"
#include "OSModule.hpp"
#include "DateModule.hpp"
#include "HostModule.hpp"
#include "SysModule.hpp"
#include "NetIfModule.hpp"
#include "RamModule.hpp"
#include <iostream>
#include <signal.h>

MonitorNcurses::MonitorNcurses(void) :
_winX(COLS), _winY(LINES),
_totX(0), _totY(3), _nextY(0),
_ch(0), _beginTime(clock()), _lastDisplay(0)
{
	/* init NCURSES */
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

	/* this->window is by default standard screen */
	this->_win = stdscr;

	/* generate one OSModule by default */
	MonitorModule *mod1 = new OSModule(0, 3);
	this->_modules.push_back(mod1);

	/* initialize */
	this->_totX = 0;
	this->_totY = 3;
	this->_nextY = mod1->getSize()[Y] + mod1->getPos()[Y];

	signal(SIGWINCH, &MonitorNcurses::resizeHandler);
};

MonitorNcurses::~MonitorNcurses(void) {
	endwin();
};

/* handler for SIGWINCH */
void		MonitorNcurses::resizeHandler(int sig) {
	if (sig == SIGWINCH) {
		endwin();
		// RESIZE NOT HANDLED
		std::cerr << "Error : resize window." << std::endl;
		exit(1);
	}
}

/* add module of type = type to vector */
void		MonitorNcurses::addModule(std::string type) {
	MonitorModule		*mod = NULL;
	MonitorModule		*last = this->_modules.back();
	std::vector<int>	lpos = last->getPos();
	std::vector<int>	lsiz = last->getSize();
	std::vector<int>	pos(2);
	pos[Y] = (lpos[Y]);
	pos[X] = (lpos[X] + lsiz[X]);

	if (this->_totX + pos[X] >= WCOLS - 1) { /* go to next line */
		pos[X] = 0;
		if (this->_nextY > pos[Y])
			pos[Y] = this->_nextY;
		else
			pos[Y] += lsiz[Y];
		this->_totY += pos[Y];
		this->_totX = 0;
	}
	if (this->_totY + pos[Y] >= WLINES - 1) {
		return;
	}

	/* choose module type */
	if (type == "standard") {
		mod = new MonitorModule(STDMONITOR_X, STDMONITOR_Y, pos[X], pos[Y]);
	} else if (type == "host") {
		mod = new HostModule(pos[X], pos[Y]);
	} else if (type == "sys") {
		mod = new SysModule(pos[X], pos[Y]);
	} else if (type == "ram") {
		mod = new RamModule(pos[X], pos[Y]);
	} else if (type == "net") {
		mod = new NetIfModule(pos[X], pos[Y]);
	} else if (type == "os") {
		mod = new OSModule(pos[X], pos[Y]);
	} else if (type == "date") {
		mod = new DateModule(pos[X], pos[Y]);
	}

	/* update */
	if (this->_nextY < mod->getSize()[Y] + mod->getPos()[Y])
		this->_nextY = mod->getSize()[Y] + mod->getPos()[Y];
	this->_modules.push_back(mod);
	this->_totX += pos[X];
}

/* get key and do action (add/delete module) */
void		MonitorNcurses::getKey(void) {
	this->_ch = getch();

	if (this->_ch == 't') {
		this->_modules[0]->writeMe(3, 3, "LOL");
	} else if (this->_ch == 'c') {
		this->_modules[0]->deleteMe();
		wclear(this->_win);
		clear();
	} else if (this->_ch == 'h') {
		this->addModule("host");
	} else if (this->_ch == 'o') {
		this->addModule("os");
	} else if (this->_ch == 'r') {
		this->addModule("ram");
	} else if (this->_ch == 's') {
		this->addModule("sys");
	} else if (this->_ch == 'n') {
		this->addModule("net");
	} else if (this->_ch == 'd') {
		this->addModule("date");
	} else if (this->_ch == '+') {
		this->addModule("standard");
	}

	if (this->_ch == 'W' || this->_ch == 'w') {
		int c = getchar();
		if ((c >= '0' && c <= '9') &&
			(c - '0' >= 0 && c - '0' < static_cast<int>(this->_modules.size())))
			this->_modules[c - '0']->deleteMe();
	}

	/* DEBUG */
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
	str.append(" next Y: ");
	str.append(std::to_string(this->_nextY));
	str.append("        h:host  o:os  r:ram  s:sys  n:net  d:date  +:void");
	str.append(std::to_string(this->_nextY));
	mvprintw(0, 0 , str.c_str());
}


int			MonitorNcurses::getCharacter(void) {
	return this->_ch;
}

/* display one single module */
void		MonitorNcurses::_displayModule(size_t n) {
	if (n < this->_modules.size()) {
		this->_modules[n]->display();
	}
}

/* refresh and display all modules */
void		MonitorNcurses::refreshWindow(void) {
	if (clock() - this->_lastDisplay < 10000) /* do not refresh too often */
		return;
	this->_lastDisplay = clock();
	wrefresh(this->_win);
	for (size_t i=0; i < this->_modules.size(); i++) {
		this->_modules[i]->display();
		this->_modules[i]->refresh();
	}
}

