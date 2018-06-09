/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:40:42 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 11:10:02 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MonitorNcurses.hpp"
#include <QApplication>
#include <QPushButton>
#include "MainWindow.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{ // ncurses
		MonitorNcurses mon;

		while (42)
		{
			mon.getKey();
			if (mon.getCharacter() == 'q' || mon.getCharacter() == 'Q')
				break;
			mon.refreshWindow();
		}
	}
	else
	{
		QApplication app(ac, av);

        MainWindow test;

        test.show();
		return app.exec();
	}
	return 0;
}
