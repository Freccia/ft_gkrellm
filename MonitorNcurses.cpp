/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorNcurses.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:48:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/13 19:07:22 by lfabbro          ###   ########.fr       */
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

typedef std::vector<MonitorModule*>::iterator	vectIter;


/* Default Constructor */
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
	this->_nextY = mod1->getSize()[C_Y] + mod1->getPos()[C_Y];

	this->addModule("sys");
	this->addModule("host");
	this->addModule("net");
	this->addModule("ram");
	this->addModule("date");

	signal(SIGWINCH, &MonitorNcurses::resizeHandler);
};

/* Default Destructor */
MonitorNcurses::~MonitorNcurses(void) {
	for (vectIter it = _modules.begin(); it != _modules.end(); ++it) {
		delete *it;
	}
	_modules.clear();
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
	pos[C_Y] = (lpos[C_Y] + lsiz[C_Y]);
	pos[C_X] = 0;

	if (this->_totY + pos[C_Y] >= WLINES - 1) {
		return;
	}

	/* choose module type */
	if (type == "standard") {
		mod = new MonitorModule(STDMONITOR_X, STDMONITOR_Y, pos[C_X], pos[C_Y]);
	} else if (type == "host") {
		mod = new HostModule(pos[C_X], pos[C_Y]);
	} else if (type == "sys") {
		mod = new SysModule(pos[C_X], pos[C_Y]);
	} else if (type == "ram") {
		mod = new RamModule(pos[C_X], pos[C_Y]);
	} else if (type == "net") {
		mod = new NetIfModule(pos[C_X], pos[C_Y]);
	} else if (type == "os") {
		mod = new OSModule(pos[C_X], pos[C_Y]);
	} else if (type == "date") {
		mod = new DateModule(pos[C_X], pos[C_Y]);
	}

	/* update */
	this->_modules.push_back(mod);
	this->_totY += pos[C_Y];
}

#include <stdio.h>
/* Remove module of type = type from vector */
void		MonitorNcurses::removeModule(std::string type)
{
	for (vectIter it = _modules.begin(); it != _modules.end(); ++it) {
		if ((*it)->getName() == type) {
			this->_totY -= (*it)->getPos()[C_Y];
			(*it)->deleteMe();
			this->_modules.erase(it);
			break;
		}
	}
	vectIter prev;
	for (vectIter it = _modules.begin(); it != _modules.end(); ++it) {
		if (it != _modules.begin()) {
			std::vector<int> posPrev = (*prev)->getPos();
			std::vector<int> sizePrev = (*prev)->getSize();
			(*it)->setPos(posPrev[C_X] + sizePrev[C_X], posPrev[C_Y] + sizePrev[C_Y]);
			prev = it;
		} else {
			prev = _modules.begin();
		}
	}
}

/* get key and do action (add/delete module) */
void		MonitorNcurses::getKey(void)
{
	std::vector<std::string> modules = {"date", "host", "net", "os", "ram", "sys"};

	this->_ch = getch();

	for (size_t i=0; i < modules.size(); i++) {
		if (this->_ch == modules[i][0])
			this->addModule(modules[i]);
	}
	if (this->_ch == 'c') {
			char mod = getchar();
			for (size_t i=0; i < modules.size(); i++) {
				if (mod == modules[i][0])
					this->removeModule(modules[i]);
			}
		wclear(this->_win);
		clear();
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
	str.append("    ");
	str.append(this->_debug.c_str());
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

