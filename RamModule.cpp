/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:00:47 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 11:37:46 by lfabbro          ###   ########.fr       */
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
#include <QBoxLayout>
#include <QRect>

#include <tgmath.h>


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

	this->_phisicalMem = ramSize;

	this->_ramSize =    "RAM:      ";
	this->_ramSize += std::to_string(ramSize / 1000000000);
	this->_ramSize +=    "GB";
	this->_ramSize = this->_ramSize.substr(0, RAMMOD_X - 2);
}

RamModule::~RamModule(void) {
}

void		RamModule::_updateRamUsage(void) {
	//char	buff[BUFF];
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

	//int64_t memUsed = this->_phisicalMem - (vmstat.free_count * 4096);
	//int64_t virtualMem = this->_phisicalMem - (vmstat.free_count * 4096);

	// TODO CHANGE ME
	//snprintf(buff, sizeof(buff), "Total: % 3.1f ", total);
	this->_ramUsage = "Total: ";
	this->_ramUsage += std::to_string(static_cast<int>(floor(total)));

	//this->_ramUsage = buff;

	// TODO CHANGE ME
	//snprintf(buff, sizeof(buff), "Wired: % 3.1f  Active: % 3.1f  Inactive: % 3.1f  Free: % 3.1f", wired, active, inactive, free);
	this->_ramUsageBis = "Wired: ";
	this->_ramUsageBis += std::to_string(static_cast<int>(floor(wired)));
	this->_ramUsageBis += " Active: ";
	this->_ramUsageBis += std::to_string(static_cast<int>(floor(active)));
	this->_ramUsageBis += " Inactive: ";
	this->_ramUsageBis += std::to_string(static_cast<int>(floor(inactive)));
	this->_ramUsageBis += " Free: ";
	this->_ramUsageBis += std::to_string(static_cast<int>(floor(free)));

	//this->_ramUsageBis = buff;
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

void RamModule::displayQT()
{
    _update();
    _labels[0]->setText(this->_ramSize.c_str());
    _labels[1]->setText(this->_ramUsage.c_str());
    _labels[2]->setText(this->_ramUsageBis.c_str());
    _labels[3]->setText(this->_ramSwap.c_str());
}
