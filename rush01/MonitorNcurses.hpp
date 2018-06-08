/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorNcurses.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:43:18 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 13:27:48 by lfabbro          ###   ########.fr       */
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

class MonitorNcurses: public IMonitorDisplay {
private:
	MonitorNcurses(MonitorNcurses const &Cc);
	MonitorNcurses &operator=(MonitorNcurses const &Cc);

	/*				*/
	int			_winX;
	int			_winY;
	int			_ch;
	clock_t		_beginTime;
	clock_t		_lastDisplay;
	std::vector<MonitorModule> _modules;

	/*				*/
	void			_displayModule(size_t n);

public:
	MonitorNcurses(void);
	virtual ~MonitorNcurses(void);

	/*				*/
	void			getKey(void);
	int				getCharacter(void);
	void			refreshWindow(void);
	static void		resizeHandler(int sig);

	WINDOW		*_win;

};

#endif
