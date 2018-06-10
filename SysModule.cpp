/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SysModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:57:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/09 11:00:44 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SysModule.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/time.h>

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
}

void		SysModule::display(void) {
	mvwprintw(this->_subWin, 1, 1, this->_cpubrand.c_str());
	mvwprintw(this->_subWin, 2, 1, this->_cpuvendor.c_str());
	mvwprintw(this->_subWin, 3, 1, this->_cpucores.c_str());
	mvwprintw(this->_subWin, 4, 1, this->_cpuclock.c_str());
	mvwprintw(this->_subWin, 5, 1, this->_cpufeatures.c_str());
};

void SysModule::displayQT(void)
{
    _labels[0]->setText(_cpubrand.c_str());
    _labels[1]->setText(_cpuvendor.c_str());
    _labels[2]->setText(_cpucores.c_str());
    _labels[3]->setText(_cpuclock.c_str());
    _labels[4]->setText(_cpufeatures.c_str());
}
