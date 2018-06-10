/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:00:47 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 15:38:02 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"
//#include <stdio.h>
#include <tgmath.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/time.h>
#include <unistd.h>
#include <mach/host_info.h>
#include <mach/mach_host.h>
#include <mach/task_info.h>
#include <mach/task.h>
#include <QBoxLayout>
#include <QRect>


#define BUFF 256

RamModule::RamModule(QFrame *fr) : MonitorModule(RAMMOD_X, RAMMOD_Y, 0, 0)
{
    _frame = fr;
    int64_t			ramSize;
    size_t			sizeBrand = sizeof(ramSize);

    sysctlbyname("hw.memsize", &ramSize, &sizeBrand, NULL, 0);

    this->_ramSize =    "RAM:      ";
    this->_ramSize += std::to_string(ramSize / 1000000000);
    this->_ramSize +=    "GB";
    this->_ramSize = this->_ramSize.substr(0, RAMMOD_X - 2);
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom, _frame);

    layout->setSizeConstraint(QLayout::SetFixedSize);
    QLabel *l1 = new QLabel(_frame);
    QLabel *l2 = new QLabel(_frame);
    QLabel *l3 = new QLabel(_frame);
    QLabel *l4 = new QLabel(_frame);
    l1->setText(_ramSize.c_str());

    _labels.push_back(l1);
    _labels.push_back(l2);
    _labels.push_back(l3);
    _labels.push_back(l4);

    layout->addWidget(l1);
    layout->addWidget(l2);
    layout->addWidget(l3);
    layout->addWidget(l4);
    _frame->setLayout(layout);
}

RamModule::RamModule(int posx, int posy):
	MonitorModule(RAMMOD_X, RAMMOD_Y, posx, posy)
{
	int64_t			ramSize;
	size_t			sizeBrand = sizeof(ramSize);

	sysctlbyname("hw.memsize", &ramSize, &sizeBrand, NULL, 0);

	this->_physicalMem = ramSize;

	this->_ramSize =    "Physical Memory:      ";
	this->_ramSize += std::to_string(ramSize / 1000000000);
	this->_ramSize +=    " GB";
	this->_ramSize = this->_ramSize.substr(0, RAMMOD_X - 2);
}

RamModule::~RamModule(void) {
}


//#define PAGESIZE getpagesize()
#define PAGESIZE 4096
#define MEGABYTES 1048576

void		RamModule::_updateRamUsage(void)
{
	//natural_t				count = HOST_VM_INFO64_COUNT;
	//struct vm_statistics64	vmstat;
	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	vm_statistics_data_t	vmstat;

	if ( host_statistics(mach_host_self(), HOST_VM_INFO,
		reinterpret_cast<host_info_t>(&vmstat), &count ) != KERN_SUCCESS) {
		return;
	}

	double total = (vmstat.wire_count + vmstat.active_count +
				vmstat.inactive_count + vmstat.free_count) * PAGESIZE / MEGABYTES;
	double wired = vmstat.wire_count * PAGESIZE / MEGABYTES;
	double active = vmstat.active_count * PAGESIZE / MEGABYTES;
	double inactive = vmstat.inactive_count * PAGESIZE / MEGABYTES;
	double free = vmstat.free_count * PAGESIZE / MEGABYTES;

	this->_ramUsage = "Total: ";
	this->_ramUsage += std::to_string(static_cast<int>(floor(total)));
	this->_ramUsage += " MB";

	this->_ramUsageBis = "Wired: ";
	this->_ramUsageBis += std::to_string(static_cast<int>(floor(wired)));
	this->_ramUsageBis += " MB  Active: ";
	this->_ramUsageBis += std::to_string(static_cast<int>(floor(active)));
	this->_ramUsageBis += " MB  Inactive: ";
	this->_ramUsageBis += std::to_string(static_cast<int>(floor(inactive)));
	this->_ramUsageBis += " MB  Free: ";
	this->_ramUsageBis += std::to_string(static_cast<int>(floor(free)));
	this->_ramUsageBis += " MB";

	/*
	int64_t memUsed = this->_physicalMem - (vmstat.free_count * 4096);
	int64_t virtualMem = this->_physicalMem - (vmstat.free_count * 4096);
	int64_t appMem = vmstat.

	this->_ramUsageTer = "Physical Mem: ";
	this->_ramUsageTer += std::to_string(this->_physicalMem);
	this->_ramUsageTer += std::to_string(this->_physicalMem);
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
	this->_ramSwap += std::to_string(ramSwap.xsu_total / MEGABYTES);
	this->_ramSwap += " MB Avail: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_avail / MEGABYTES);
	this->_ramSwap += " MB Used: ";
	this->_ramSwap += std::to_string(ramSwap.xsu_used / MEGABYTES);
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
	mvwprintw(this->_subWin, 4, 1, this->_ramUsageTer.c_str());
	mvwprintw(this->_subWin, 5, 1, this->_ramSwap.c_str());
}

void RamModule::displayQT()
{
    _update();
    _labels[0]->setText(this->_ramSize.c_str());
    _labels[1]->setText(this->_ramUsage.c_str());
    _labels[2]->setText(this->_ramUsageBis.c_str());
    _labels[3]->setText(this->_ramSwap.c_str());
}
