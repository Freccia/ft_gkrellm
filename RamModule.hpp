/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:59:40 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 22:53:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RamModule_hpp
#define RamModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>

#define RAMMOD_X 80
#define RAMMOD_Y 10

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
	uint64_t	_physicalMem;
	/**/
	double		_total;
	double		_wired;
	double		_active;
	double		_inactive;
	double		_free;
	/**/
	double		_used;
	double		_virtual;
	double		_app;
	double		_compressed;
	/* SWAP */
	double		_xsu_total;
	double		_xsu_avail;
	double		_xsu_used;
	double		_xsu_encrypted;
	/**/
	int64_t			_phisicalMem;
	std::string		_ramSize;
	std::string		_ramSwap;
	std::string		_ramUsage;
	std::string		_ramUsageBis;
	std::string		_ramUsageTer;
	std::string		_progressRAM;
	std::string		_progressSWAP;

	/* MEMBERS FUNCTIONS */
	void		_updateRamUsage(void);
	void		_updateRamUsageBis(void);
	void		_updateRamUsageTer(void);
	std::string	_progressBar(double percent);

public:
	RamModule(int posx, int posy);
    RamModule(QFrame *);
	~RamModule(void);

	/**/
	void		display(void);
    void displayQT(void);
};

#endif
