/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SysModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:57:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 22:03:34 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SysModule.hpp"
#include <sys/sysctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <mach/mach.h>
#include <mach/processor_info.h>
#include <mach/mach_host.h>
#include <tgmath.h> /* floor() */

#define BUFF 256


SysModule::SysModule(QFrame *fr):
    MonitorModule(SYSMOD_X, SYSMOD_Y, 0, 0)
{
    _init();
    _frame = fr;
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom, _frame);

    layout->setSizeConstraint(QLayout::SetMinimumSize);
    QLabel *l1 = new QLabel(_frame);
    QLabel *l2 = new QLabel(_frame);
    QLabel *l3 = new QLabel(_frame);
    QLabel *l4 = new QLabel(_frame);
    QLabel *l5 = new QLabel(_frame);

    _labels.push_back(l1);
    _labels.push_back(l2);
    _labels.push_back(l3);
    _labels.push_back(l4);
    _labels.push_back(l5);

    layout->addWidget(l1);
    layout->addWidget(l2);
    layout->addWidget(l3);
    layout->addWidget(l4);
    layout->addWidget(l5);
    _frame->setLayout(layout);
};

SysModule::SysModule(int posx, int posy):
	MonitorModule(SYSMOD_X, SYSMOD_Y, posx, posy)
{
    _init();
};

SysModule::~SysModule(void) {
};

void SysModule::_init()
{
    char			cpubrand[BUFF];
    size_t			sizeBrand = BUFF;
    char			cpuvendor[BUFF];
    size_t			sizeVend = BUFF;
    int32_t			cpucores;
    size_t			sizeCore = sizeof(cpucores);
    struct clockinfo cpuclock;
    size_t			sizeClock = sizeof(cpuclock);
    char			cpufeatures[BUFF];
    size_t			sizeFeat = BUFF;

    sysctlbyname("machdep.cpu.brand_string", &cpubrand, &sizeBrand, NULL, 0);
    sysctlbyname("machdep.cpu.vendor", &cpuvendor, &sizeVend, NULL, 0);
    sysctlbyname("machdep.cpu.cores_per_package", &cpucores, &sizeCore, NULL, 0);
    sysctlbyname("kern.clockrate", &cpuclock, &sizeClock, NULL, 0);
    sysctlbyname("machdep.cpu.extfeatures", &cpufeatures, &sizeFeat, NULL, 0);

    this->_cpubrand =    "CPU:      ";
    this->_cpubrand += cpubrand;
    this->_cpubrand = this->_cpubrand.substr(0, SYSMOD_X - 2);

    this->_cpuvendor =   "Vendor:   ";
    this->_cpuvendor += cpuvendor;
    this->_cpuvendor = this->_cpuvendor.substr(0, SYSMOD_X - 2);

    this->_cpucores =    "Cores:    ";
    this->_cpucores += std::to_string(cpucores);
    this->_cpucores = this->_cpucores.substr(0, SYSMOD_X - 2);

    this->_cpuclock =    "Clock:    ";
    this->_cpuclock += std::to_string(cpuclock.hz);
    this->_cpuclock += "Hz";

    this->_cpufeatures = "Features: ";
    this->_cpufeatures += cpufeatures;
    this->_cpufeatures = this->_cpufeatures.substr(0, SYSMOD_X - 2);
    this->_cpuclock = this->_cpuclock.substr(0, SYSMOD_X - 2);

	this->_updateCPULoad();
}

void		SysModule::_updateCPULoad(void) {

	processor_cpu_load_info_t	cpuLoad;
	mach_msg_type_number_t		processorMsgCount;
	natural_t					processorCount;

	if (host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &processorCount, (processor_info_array_t *)&cpuLoad, &processorMsgCount) != KERN_SUCCESS)
		return;

	this->_NCores = processorCount;

	for (natural_t core = 0; core < processorCount; core++)
	{
		// Calc load types and totals, with guards against 32-bit overflow
		// (values are natural_t)
		this->_system[core] = cpuLoad[core].cpu_ticks[CPU_STATE_SYSTEM];
		this->_user[core] = cpuLoad[core].cpu_ticks[CPU_STATE_USER];
		this->_idle[core] = cpuLoad[core].cpu_ticks[CPU_STATE_IDLE];

		this->_total[core] = this->_system[core] +
								this->_user[core] + this->_idle[core];

		if (this->_total[core] < 1)
			this->_total[core] = 1;

		this->_totalCPUTime += this->_total[core];
		this->_totalSystemTime += this->_system[core];
		this->_totalUserTime += this->_user[core];
		this->_totalIdleTime += this->_idle[core];
	}
}


void		SysModule::display(void) {
	this->_updateCPULoad();
	int		x = 2;
	int		y = 0;
	mvwprintw(this->_subWin, ++y, x, this->_cpubrand.c_str());
	mvwprintw(this->_subWin, ++y, x, this->_cpuvendor.c_str());
	mvwprintw(this->_subWin, ++y, x, this->_cpucores.c_str());
	mvwprintw(this->_subWin, ++y, x, this->_cpuclock.c_str());
	mvwprintw(this->_subWin, ++y, x, this->_cpufeatures.c_str());

	++y;
	std::string		tmp;
	tmp = "TOTAL: ";
	tmp += std::to_string(this->_totalCPUTime).c_str();
	tmp += "  System: ";
	tmp += std::to_string(this->_totalSystemTime).c_str();
	tmp += "  User: ";
	tmp += std::to_string(this->_totalUserTime).c_str();
	tmp += "  Idle: ";
	tmp += std::to_string(this->_totalIdleTime).c_str();
	mvwprintw(this->_subWin, ++y, x, tmp.c_str());

	/*
	double sys = static_cast<double>(_totalSystemTime) / static_cast<double>(_totalCPUTime) * 100;
	double usr = static_cast<double>(_totalUserTime) / static_cast<double>(_totalCPUTime) * 100;
	double idl = static_cast<double>(_totalIdleTime) / static_cast<double>(_totalCPUTime) * 100;

	tmp = "TOTAL: ";
	tmp += std::to_string(this->_totalCPUTime).c_str();
	tmp += "  System: ";
	tmp += std::to_string(sys).c_str();
	tmp += "  User: ";
	tmp += std::to_string(usr).c_str();
	tmp += "  Idle: ";
	tmp += std::to_string(idl).c_str();
	mvwprintw(this->_subWin, ++y, x, tmp.c_str());
	*/

	for (uint32_t core = 0; core < _NCores; core++) {
		tmp = std::to_string(core);
		tmp += ". System: ";
		tmp += std::to_string(this->_system[core]).c_str();
		tmp += "  User: ";
		tmp += std::to_string(this->_user[core]).c_str();
		tmp += "  Idle: ";
		tmp += std::to_string(this->_idle[core]).c_str();
		tmp += "  Total: ";
		tmp += std::to_string(this->_total[core]).c_str();
		/*
		tmp += "  :: ";
		double		percent = static_cast<double>(_total[core]) /
								static_cast<double>(_totalSystemTime) * 100;
		//tmp += std::to_string(static_cast<unsigned int>(floor(percent))).c_str();
		tmp += std::to_string(floor(percent)).c_str();
		*/
		mvwprintw(this->_subWin, ++y, x, tmp.c_str());
	}
}

void SysModule::displayQT(void)
{
    _labels[0]->setText(_cpubrand.c_str());
    _labels[1]->setText(_cpuvendor.c_str());
    _labels[2]->setText(_cpucores.c_str());
    _labels[3]->setText(_cpuclock.c_str());
    _labels[4]->setText(_cpufeatures.c_str());
}
