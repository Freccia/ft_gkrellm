/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorNcurses.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:43:18 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 16:26:40 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MonitorNcurses_hpp
#define MonitorNcurses_hpp

#include "IMonitorDisplay.hpp"
#include "MonitorModule.hpp"
#include <ncurses.h>
#include <time.h>

#define WINBOX_X 0
#define WINBOX_Y 0
#define MINWIN_Y 50
#define MINWIN_X 30

#define WCOLS getmaxy(stdscr)
#define WLINES getmaxx(stdscr)

class MonitorNcurses: public IMonitorDisplay {
private:
	MonitorNcurses(MonitorNcurses const &Cc);
	MonitorNcurses &operator=(MonitorNcurses const &Cc);

	/*				*/
	int			_winX;
	int			_winY;
	int			_totX;
	int			_totY;
	int			_ch;
	clock_t		_beginTime;
	clock_t		_lastDisplay;
	std::vector<MonitorModule*> _modules;

	/*				*/
	void			_displayModule(size_t n);

public:
	MonitorNcurses(void);
	virtual ~MonitorNcurses(void);

	/*				*/
	void			getKey(void);
	int				getCharacter(void);
	void			addModule(std::string type);
	void			refreshWindow(void);
	static void		resizeHandler(int sig);

	WINDOW		*_win;

};

#endif
