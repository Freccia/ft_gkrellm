/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetIfModule.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:37:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 12:11:43 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetIfModule.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if_dl.h>
#include <ifaddrs.h>
#include <QLayout>
#include <QFrame>
#include <QLabel>

#define BUFF 256

/* to convert a number to hex (string) */
std::string c2hex(unsigned char c);

//template< typename T >
std::string nToHex( unsigned char i );


NetIfModule::NetIfModule(QFrame *fr) :
    MonitorModule(NETIFMOD_X, NETIFMOD_Y, 0, 0)
{
    _frame = fr;
    int i = IFAMAX;
    _frame = fr;
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom, _frame);

    layout->setSizeConstraint(QLayout::SetMinimumSize);
    while (i --> 0)
    {
        QLabel *l = new QLabel(_frame);
        layout->addWidget(l);
        _labels.push_back(l);
    }
    _frame->setLayout(layout);
}

NetIfModule::NetIfModule(int posx, int posy):
	MonitorModule(NETIFMOD_X, NETIFMOD_Y, posx, posy)
{
}

NetIfModule::~NetIfModule(void) {
}

void		NetIfModule::_update(void) {
	struct ifaddrs		*ptr;
	int					i = 0;
	char				buf[BUFF];
	unsigned char		*tmp;

	if (getifaddrs(&ptr) != 0)
		return;
	while (ptr != NULL && i < IFAMAX) {
		if ((ptr->ifa_addr)->sa_family == AF_LINK)
		{
			this->_interface[i] = ptr->ifa_name;

			this->_interface[i] += "	ether: ";
			if (ptr->ifa_addr)
			{
				tmp = (unsigned char *)LLADDR((struct sockaddr_dl *)(ptr)->ifa_addr);
				sprintf(buf, "%02x:%02x:%02x:%02x:%02x:%02x",
						*tmp, *(tmp+1), *(tmp+2), *(tmp+3), *(tmp+4), *(tmp+5));
				this->_interface[i] += buf;
			}

			this->_interface[i] += " mask: ";
			if (ptr->ifa_addr)
			{
				tmp = (unsigned char *)LLADDR((struct sockaddr_dl *)(ptr)->ifa_addr);
				for (int k=0; k < 6; k++) {
					if (k > 0)
						this->_interface[i] += ":";
					this->_interface[i] += c2hex(*(tmp + k));
				}
			}
			this->_interface[i] = this->_interface[i].substr(0, NETIFMOD_X - 2);
			i++;
		}
		ptr = ptr->ifa_next;
	}
}

void		NetIfModule::display(void) {
	this->_update();
	for (int i=0; i < IFAMAX; i++) {
		mvwprintw(this->_subWin, i + 1, 1, this->_interface[i].c_str());
	}
}

void NetIfModule::displayQT(void)
{
    this->_update();
    for (int i=0; i < IFAMAX; i++) {
        _labels[i]->setText(_interface[i].c_str());
    }
}
