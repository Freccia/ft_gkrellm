/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:59:40 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 19:56:00 by lfabbro          ###   ########.fr       */
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
	/* RAM */
	uint64_t			_physicalMem;
	/**/
	uint64_t		_total;
	uint64_t		_wired;
	uint64_t		_active;
	uint64_t		_inactive;
	uint64_t		_free;
	/**/
	uint64_t		_used;
	uint64_t		_virtual;
	uint64_t		_app;
	uint64_t		_compressed;
	/* SWAP */
	uint64_t		_xsu_total;
	uint64_t		_xsu_avail;
	uint64_t		_xsu_used;
	uint64_t		_xsu_encrypted;
	/**/
	std::string		_ramSize;
	std::string		_ramSwap;
	std::string		_ramUsage;
	std::string		_ramUsageBis;
	std::string		_ramUsageTer;

	/* MEMBERS FUNCTIONS */
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
