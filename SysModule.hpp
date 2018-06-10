/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SysModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:55:45 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 22:03:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SysModule_hpp
#define SysModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>
#include <QBoxLayout>
#include <QRect>

#define SYSMOD_X 92
#define SYSMOD_Y 14

/* TODO  for now this just do the trick */
#define CORES 16

class SysModule: public MonitorModule {
private:
	/**/
	SysModule(void);
	SysModule(SysModule const &Cc);
	SysModule &operator=(SysModule const &Cc);
	/**/
	std::string		_cpubrand;
	std::string		_cpuvendor;
	std::string		_cpufeatures;
	std::string		_cpucores;
	std::string		_cpuclock;
	/**/
	uint32_t		_NCores;
	uint64_t		_system[CORES];
	uint64_t		_user[CORES];
	uint64_t		_idle[CORES];
	uint64_t		_total[CORES];
	uint64_t		_totalCPUTime;
	uint64_t		_totalSystemTime;
	uint64_t		_totalUserTime;
	uint64_t		_totalIdleTime;

	/* MEMBER FUNCTIONS */
	void			_updateCPULoad(void);
	void			_init(void);

public:
	//SysModule(int width, int height, int x, int y);
	SysModule(int posx, int posy);
	SysModule(QFrame *fr);
	~SysModule(void);

	/**/
	void		display(void);
    void displayQT(void);
};

#endif
