/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:16:45 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 13:31:39 by lfabbro          ###   ########.fr       */
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

class MonitorModule: public IMonitorModule {
private:
	MonitorModule(void);

	/*				*/
	std::vector<int>	_size;
	clock_t				_lastDisplay;

public:
	MonitorModule(int x, int y);
	MonitorModule(WINDOW *father, int x, int y);
	MonitorModule(MonitorModule const &Cc);
	virtual ~MonitorModule(void);
	MonitorModule &operator=(MonitorModule const &Cc);

	/*				*/
	WINDOW					*subWin;

	/*				*/
	std::vector<int>		getSize(void);
	void					deleteMe(void);
	void					writeMe(int x, int y, std::string str);
	void					refresh(void);
};

#endif
