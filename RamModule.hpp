/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:59:40 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 16:34:26 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RamModule_hpp
#define RamModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>

#define RAMMOD_X 100
#define RAMMOD_Y 7

//#define PAGESIZE getpagesize()
#define PAGESIZE 4096.0
#define MEGABYTES 1048576

class RamModule: public MonitorModule {
private:
	/**/
	RamModule(void);
	RamModule(RamModule const &Cc);
	RamModule &operator=(RamModule const &Cc);
	/**/
	int64_t			_physicalMem;
	std::string		_ramSize;
	std::string		_ramSwap;
	std::string		_ramUsage;
	std::string		_ramUsageBis;
	std::string		_ramUsageTer;

	/**/
	void		_updateRamUsage(void);
	void		_updateRamUsageBis(void);
	void		_updateRamUsageTer(void);

public:
	RamModule(int posx, int posy);
    RamModule(QFrame *);
	~RamModule(void);

	/**/
	void		display(void);
    void displayQT(void);
};

#endif
