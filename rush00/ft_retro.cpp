/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:16:28 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/30 18:03:39 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

#include "Player.hpp"

#define DELAY 30000

void		init_player(Player *pl)
{
	pl->setPosition(0, 0);
	pl->setShape(">");
	pl->setLifes(3);
}

int			main(void)
{
	WINDOW			*box;
	Player			pl;
	//int				size = pl.getShapeSize();
	int				ch;

	(void)box;

	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE); // non-blocking manner -- it will return ERR if the key input is not ready
	keypad(stdscr, TRUE);
	curs_set(FALSE);

	init_player(&pl);

	while(42)
	{
		ch = getch();

		clear();
		if (ch == KEY_LEFT) {
			if (pl.getPosX() > 0)
				pl.setPosition(pl.getPosX() - 1, pl.getPosY());
		}
		else if (ch == KEY_RIGHT) {
			if (pl.getPosX() < COLS)
				pl.setPosition(pl.getPosX() + 1, pl.getPosY());
		}
		else if (ch == KEY_UP) {
			if (pl.getPosX() > 0)
				pl.setPosition(pl.getPosX(), pl.getPosY() - 1);
		}
		else if (ch == KEY_DOWN) {
			if (pl.getPosX() < LINES)
				pl.setPosition(pl.getPosX(), pl.getPosY() + 1);
		}
		//mvprintw(LINES/2, (COLS / 2) - (size / 2), pl.getShape().c_str());
		mvprintw(pl.getPosY(), pl.getPosX(), pl.getShape().c_str());
		refresh();
		if (ch == 'q' || ch == 'Q')
			break;
	}

	endwin();

	return 0;
}
