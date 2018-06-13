/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:34:56 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/13 19:10:29 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSModule.hpp"
#include <limits.h>
#include <sys/utsname.h>
#include <QBoxLayout>
#include <QRect>
#include <QFrame>

OSModule::OSModule(int posx, int posy):
	MonitorModule(OSMOD_X, OSMOD_Y, posx, posy, "os", "  OS Info  ")
{
    _init();
}

OSModule::OSModule(QFrame *fr):
    MonitorModule(OSMOD_X, OSMOD_Y, 0, 0, "os", "  OS Info  ")
{
    _init();
    _frame = fr;
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom, _frame);

    QLabel * title = new QLabel(_name.c_str());
    layout->addWidget(title);
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
}

OSModule::~OSModule(void) {
}

void OSModule::_init()
{
    struct utsname *name = new struct utsname ();

    if (uname(name)) {
        this->_sysname = "Error";
        this->_nodename = "Error";
        this->_release = "Error";
        this->_version = "Error";
        this->_machine = "Error";
    } else {
        this->_sysname = name->sysname;
        this->_nodename = name->nodename;
        this->_release = name->release;
        this->_version = name->version;
        this->_machine = name->machine;
    }
	delete name;
}

void		OSModule::display(void) {
	/* truncate */
	std::string title = this->_title.substr(0, OSMOD_X - 2);
	std::string sysname = this->_sysname.substr(0, OSMOD_X - 2);
	std::string nodename = this->_nodename.substr(0, OSMOD_X - 2);
	std::string release = this->_release.substr(0, OSMOD_X - 2);
	std::string version = this->_version.substr(0, OSMOD_X - 2);
	std::string machine = this->_machine.substr(0, OSMOD_X - 2);
	int x = 2;
	int y = -1;
	/* display */
	box(this->_subWin, '|', '-');
	mvwprintw(this->_subWin, ++y, x, title.c_str());
	mvwprintw(this->_subWin, ++y, x, sysname.c_str());
	mvwprintw(this->_subWin, ++y, x, nodename.c_str());
	mvwprintw(this->_subWin, ++y, x, release.c_str());
	mvwprintw(this->_subWin, ++y, x, version.c_str());
	mvwprintw(this->_subWin, ++y, x, machine.c_str());
};

void OSModule::displayQT(void)
{
    _labels[0]->setText(_sysname.c_str());
    _labels[1]->setText(_nodename.c_str());
    _labels[2]->setText(_release.c_str());
    _labels[3]->setText(_version.c_str());
    _labels[4]->setText(_machine.c_str());
}
