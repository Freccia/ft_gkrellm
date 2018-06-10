/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:46:32 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 22:29:14 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostModule.hpp"
#include <unistd.h>

#define BUFF 256


HostModule::HostModule(QFrame *fr):
    MonitorModule(HOSTMOD_X, HOSTMOD_Y, 0, 0, "  Host  ")
{
    _init();
    _frame = fr;
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom, _frame);

    layout->setSizeConstraint(QLayout::SetMinimumSize);
    QLabel *l1 = new QLabel(_frame);
    QLabel *l2 = new QLabel(_frame);


    _labels.push_back(l1);
    _labels.push_back(l2);

    layout->addWidget(l1);
    layout->addWidget(l2);
    _frame->setLayout(layout);
}
HostModule::HostModule(int posx, int posy):
	MonitorModule(HOSTMOD_X, HOSTMOD_Y, posx, posy, "  Host  ")
{
    _init();
};

void HostModule::_init()
{
    char hostname[BUFF];
    char username[BUFF];

    gethostname(hostname, BUFF);
    getlogin_r(username, BUFF);

    this->_hostname = hostname;
    this->_hostname = this->_hostname.substr(0, HOSTMOD_X - 2); /* truncate */
    this->_username = username;
    this->_username = this->_username.substr(0, HOSTMOD_X - 2);
}

HostModule::~HostModule(void) {
};

void		HostModule::display(void) {
	int x = 2;
	int y = -1;
	box(this->_subWin, '|', '-');
	mvwprintw(this->_subWin, ++y, x, this->_name.c_str());
	mvwprintw(this->_subWin, ++y, x, this->_hostname.c_str());
	mvwprintw(this->_subWin, ++y, x, this->_username.c_str());
};

void		HostModule::displayQT(void) {
    _labels[0]->setText(this->_hostname.c_str());
    _labels[1]->setText(this->_username.c_str());
};
