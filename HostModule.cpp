/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:46:32 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/13 19:08:36 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostModule.hpp"
#include <unistd.h>

#define BUFF 256


HostModule::HostModule(QFrame *fr):
    MonitorModule(HOSTMOD_X, HOSTMOD_Y, 0, 0, "host", "  Host  ")
{
    _init();
    _frame = fr;
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom, _frame);

    QLabel * title = new QLabel(_name.c_str());
    layout->addWidget(title);
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
	MonitorModule(HOSTMOD_X, HOSTMOD_Y, posx, posy, "host", "  Host  ")
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
    this->_username = username;
}

HostModule::~HostModule(void) {
};

void		HostModule::display(void) {
	std::string		title;
	std::string		hostname;
	std::string		username;
	int x = 2;
	int y = -1;

	/* truncate */
	title = this->_title.substr(0, HOSTMOD_X - 3);
	hostname = this->_hostname.substr(0, HOSTMOD_X - 3);
	username = this->_username.substr(0, HOSTMOD_X - 3);
	/* display */
	box(this->_subWin, '|', '-');
	mvwprintw(this->_subWin, ++y, x, title.c_str());
	mvwprintw(this->_subWin, ++y, x, hostname.c_str());
	mvwprintw(this->_subWin, ++y, x, username.c_str());
};

void		HostModule::displayQT(void) {
    _labels[0]->setText(this->_hostname.c_str());
    _labels[1]->setText(this->_username.c_str());
};
