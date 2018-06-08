/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorNcurses.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:48:08 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 13:33:23 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorNcurses.hpp"
#include <iostream>
#include <signal.h>

MonitorNcurses::MonitorNcurses(void) :
_winX(COLS), _winY(LINES),
_ch(0), _beginTime(clock()), _lastDisplay(0)
{
	this->_win = initscr();
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

	//this->_win = subwin(stdscr, this->_winY, this->_winX, WINBOX_Y, WINBOX_X);
	box(_win, '|', '-');

	MonitorModule mod1(this->_win, 20, 10);
	this->_modules.push_back(mod1);

	this->_modules[0].writeMe(5, 5, "HOLA");

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

void		MonitorNcurses::getKey(void) {
	this->_ch = getch();
	if (this->_ch == 't') {
		mvwprintw(this->_modules[0].subWin, 9, 9, "TTTT");
		mvprintw(11, 5, "Hello I'm Mr T");
		this->_modules[0].writeMe(3, 3, "LOL");
	}
	else if (this->_ch == 'c') {
		this->_modules[0].deleteMe();
		wclear(this->_win);
	}
	else if (this->_ch == 'W' || this->_ch == 'w') {
		int c = getchar();
		if ((c >= '0' && c <= '9') &&
			(c - '0' >= 0 && c - '0' < static_cast<int>(this->_modules.size())))
			this->_modules[c - '0'].deleteMe();
	}
}

int			MonitorNcurses::getCharacter(void) {
	return this->_ch;
}

void		MonitorNcurses::_displayModule(size_t n) {
	if (n < this->_modules.size())
		this->_modules[n].refresh();
}

void		MonitorNcurses::refreshWindow(void) {
	this->_lastDisplay = clock();
	box(_win, '|', '-');
	wrefresh(stdscr);
	wrefresh(this->_win);
	for (size_t i=0; i < this->_modules.size(); i++) {
		this->_modules[i].refresh();
	}
}

