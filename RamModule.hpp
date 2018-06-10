/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:59:40 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 11:28:47 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RamModule_hpp
#define RamModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>

#define RAMMOD_X 84
#define RAMMOD_Y 7

class RamModule: public MonitorModule {
private:
	/**/
	RamModule(void);
	RamModule(RamModule const &Cc);
	RamModule &operator=(RamModule const &Cc);
	/**/
	int64_t			_phisicalMem;
	std::string		_ramSize;
	std::string		_ramSwap;
	std::string		_ramUsage;
	std::string		_ramUsageBis;

	/**/
	void		_update(void);
	void		_updateRamUsage(void);

public:
	RamModule(int posx, int posy);
    RamModule(QFrame *);
	~RamModule(void);

	/**/
	void		display(void);
    void displayQT(void);
};

#endif
