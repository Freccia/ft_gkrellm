/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:16:28 by lfabbro           #+#    #+#             */
/*   Updated: 2018/05/30 15:21:59 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <string.h>

int			main(void)
{
	WINDOW			*box;
	std::string		msg = "Texte au centre";
	int				size = std::strlen(msg.c_str());

	(void)box;

	initscr();
	while(1) {
		clear();    // Efface la fenêtre (donc l'ancien message)
		mvprintw(LINES/2, (COLS / 2) - (size / 2), msg.c_str());
		refresh();
		if(getch() != 410)
			break;
	}

	endwin();

	return 0;
}
