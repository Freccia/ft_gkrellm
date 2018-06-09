/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:00:47 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/09 11:32:46 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/time.h>

#define BUFF 256

RamModule::RamModule(int posx, int posy):
	MonitorModule(RAMMOD_X, RAMMOD_Y, posx, posy)
{
	int64_t			ramSize;
	size_t			sizeBrand = sizeof(ramSize);
	struct xsw_usage ramSwap;
	size_t			sizeUsage = sizeof(ramSwap);

	sysctlbyname("hw.memsize", &ramSize, &sizeBrand, NULL, 0);
	sysctlbyname("vm.swapusage", &ramSwap, &sizeUsage, NULL, 0);

	this->_ramSize =    "RAM:      ";
	this->_ramSize += std::to_string(ramSize / 1000000000);
	this->_ramSize +=    "GB";
	this->_ramSize = this->_ramSize.substr(0, RAMMOD_X - 2);

	this->_ramSwap =  "SWAP:  ";
	this->_ramSwap += "Total: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_total / 1000000);
	this->_ramSwap += "MB Avail: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_avail / 1000000);
	this->_ramSwap += "MB Used: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_used / 1000000);
	this->_ramSwap += "MB";
	if (ramSwap.xsu_encrypted)
		this->_ramSwap += " (encrypted)";
	this->_ramSwap = this->_ramSwap.substr(0, RAMMOD_X - 2);
}

RamModule::~RamModule(void) {
}

void		RamModule::update(void)
{
	struct xsw_usage ramSwap;
	size_t			sizeUsage = sizeof(ramSwap);

	sysctlbyname("vm.swapusage", &ramSwap, &sizeUsage, NULL, 0);

	this->_ramSwap =  "SWAP:  ";
	this->_ramSwap += "Total: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_total / 1000000);
	this->_ramSwap += "MB Avail: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_avail / 1000000);
	this->_ramSwap += "MB Used: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_used / 1000000);
	this->_ramSwap += "MB";
	if (ramSwap.xsu_encrypted)
		this->_ramSwap += " (encrypted)";
	this->_ramSwap = this->_ramSwap.substr(0, RAMMOD_X - 2);
}

void		RamModule::display(void) {
	this->update();
	mvwprintw(this->_subWin, 1, 1, this->_ramSize.c_str());
	mvwprintw(this->_subWin, 2, 1, this->_ramSwap.c_str());
}
