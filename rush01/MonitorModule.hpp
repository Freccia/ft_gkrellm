/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:16:45 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 16:50:11 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MonitorModule_hpp
#define MonitorModule_hpp

#include "IMonitorModule.hpp"
#include <ncurses.h>
#include <vector>
#include <iostream>

#define X 0
#define Y 1

#define STDMONITOR_X 20
#define STDMONITOR_Y 10

class MonitorModule: public IMonitorModule {
protected:
	MonitorModule(void);

	/*				*/
	std::vector<int>	_size;
	std::vector<int>	_pos;
	clock_t				_lastDisplay;
	WINDOW				*_subWin;

public:
	MonitorModule(int width, int height, int x, int y);
	MonitorModule(MonitorModule const &Cc);
	virtual ~MonitorModule(void);
	MonitorModule &operator=(MonitorModule const &Cc);

	/*				*/
	std::vector<int>		getSize(void);
	std::vector<int>		getPos(void);
	void					deleteMe(void);
	void					writeMe(int x, int y, std::string str);
	void					refresh(void);
	/*				*/
	virtual void			display(void);
};

#endif
