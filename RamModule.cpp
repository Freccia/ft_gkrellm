/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:00:47 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/09 15:21:32 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/time.h>
#include <mach/host_info.h>
#include <mach/mach_host.h>
#include <mach/task_info.h>
#include <mach/task.h>

#define BUFF 256

RamModule::RamModule(int posx, int posy):
	MonitorModule(RAMMOD_X, RAMMOD_Y, posx, posy)
{
	int64_t			ramSize;
	size_t			sizeBrand = sizeof(ramSize);

	sysctlbyname("hw.memsize", &ramSize, &sizeBrand, NULL, 0);

	this->_ramSize =    "RAM:      ";
	this->_ramSize += std::to_string(ramSize / 1000000000);
	this->_ramSize +=    "GB";
	this->_ramSize = this->_ramSize.substr(0, RAMMOD_X - 2);
}

RamModule::~RamModule(void) {
}

void		RamModule::_updateRamUsage(void) {
	char	memLabel[BUFF];
	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;

	vm_statistics_data_t vmstat;
	if ( host_statistics(mach_host_self(), HOST_VM_INFO,
		reinterpret_cast<host_info_t>(&vmstat), &count ) != KERN_SUCCESS) {
		return;
	}

	double total = vmstat.wire_count + vmstat.active_count +
					vmstat.inactive_count + vmstat.free_count;
	double wired = vmstat.wire_count; //  / total;
	double active = vmstat.active_count; //  / total;
	double inactive = vmstat.inactive_count;//  / total;
	double free = vmstat.free_count ;// / total;

	// TODO CHANGE ME
	snprintf(memLabel, sizeof(memLabel), "Total: % 3.1f ", total);

	this->_ramUsage = memLabel;

	// TODO CHANGE ME
	snprintf(memLabel, sizeof(memLabel), "Wired: % 3.1f  Active: % 3.1f  Inactive: % 3.1f  Free: % 3.1f", wired, active, inactive, free);

	this->_ramUsageBis = memLabel;

	/*
	int		mib[6];
	int		pagesize;
	size_t	length;

	mib[0] = CTL_HW;
	mib[1] = HW_PAGESIZE;
	length = sizeof (pagesize);

	if (sysctl (mib, 2, &pagesize, &length, NULL, 0) < 0) {
		return;
	}
	*/
	/*
	task_basic_info_64_data_t info;
	unsigned size = sizeof (info);
	task_info (mach_task_self (), TASK_BASIC_INFO_64, (task_info_t) &info, &size);

	double unit = 1024 * 1024;
	char memLabel[BUFF];
	snprintf(memLabel, sizeof(memLabel), "% 3.1f MB\n% 3.1f MB\n% 3.1f MB",
		vmstat.free_count * pagesize / unit,
		(vmstat.free_count + vmstat.inactive_count) * pagesize / unit,
		info.resident_size / unit);
	*/
}

void		RamModule::_update(void)
{
	this->_updateRamUsage();

	struct xsw_usage ramSwap;
	size_t			sizeUsage = sizeof(ramSwap);

	sysctlbyname("vm.swapusage", &ramSwap, &sizeUsage, NULL, 0);

	this->_ramSwap =  "SWAP:  ";
	this->_ramSwap += "Total: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_total / 1000000);
	this->_ramSwap += " MB Avail: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_avail / 1000000);
	this->_ramSwap += " MB Used: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_used / 1000000);
	this->_ramSwap += " MB";
	if (ramSwap.xsu_encrypted)
		this->_ramSwap += " (encrypted)";
	this->_ramSwap = this->_ramSwap.substr(0, RAMMOD_X - 2);
}

void		RamModule::display(void) {
	this->_update();
	mvwprintw(this->_subWin, 1, 1, this->_ramSize.c_str());
	mvwprintw(this->_subWin, 2, 1, this->_ramUsage.c_str());
	mvwprintw(this->_subWin, 3, 1, this->_ramUsageBis.c_str());
	mvwprintw(this->_subWin, 5, 1, this->_ramSwap.c_str());
}
