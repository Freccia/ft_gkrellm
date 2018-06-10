/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetIfModule.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:37:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 17:48:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetIfModule.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if_dl.h>
#include <ifaddrs.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
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
	struct ifaddrs		*ifa;
	struct ifaddrs		*ptr;
	int					i = -1;
	char				*last = NULL;
	unsigned char		*tmp;
	void				*tmpIP;

	if (getifaddrs(&ifa) != 0)
		return;
	ptr = ifa;
	while (ptr != NULL && i < IFAMAX) {
		if (ptr->ifa_addr)
		{
			if (last != ptr->ifa_name) {
				last = ptr->ifa_name;
				i++;
			}
			/* Interface name */
			if (this->_interface[i].name.empty())
				this->_interface[i].name = ptr->ifa_name;
			/* Link layer interface */
			if ((ptr->ifa_addr)->sa_family == AF_LINK)
			{
				if (ptr->ifa_addr) {
					this->_interface[i].ether = "";
					tmp = (unsigned char *)LLADDR((struct sockaddr_dl *)(ptr)->ifa_addr);
					for (int k=0; k < 6; k++) {
						if (k > 0)
							this->_interface[i].ether += ":";
						this->_interface[i].ether += c2hex(*(tmp + k));
					}
				}
			}
			/* IPv4 */
			else if ((ptr->ifa_addr)->sa_family == AF_INET) {
				this->_interface[i].ipv4 = "";
				char	buf[INET_ADDRSTRLEN];
				tmpIP = &((struct sockaddr_in*)ptr->ifa_addr)->sin_addr;
				inet_ntop(AF_INET, tmpIP, buf, INET_ADDRSTRLEN);
				if (this->_interface[i].ipv4.empty() == false)
					this->_interface[i].ipv4 += "  ";
				this->_interface[i].ipv4 += buf;
			}
			/* IPv6 */
			else if ((ptr->ifa_addr)->sa_family == AF_INET6) {
				this->_interface[i].ipv6 = "";
				char	buf[INET6_ADDRSTRLEN];
				tmpIP = &((struct sockaddr_in6*)ptr->ifa_addr)->sin6_addr;
				inet_ntop(AF_INET6, tmpIP, buf, INET6_ADDRSTRLEN);
				if (this->_interface[i].ipv6.empty() == false)
					this->_interface[i].ipv6 += "  ";
				this->_interface[i].ipv6 += buf;
			}
		}
		ptr = ptr->ifa_next;
	}
	if (ifa!=NULL)
		freeifaddrs(ifa);
}


void		NetIfModule::display(void) {
	this->_update();
	for (int i=0; i < IFAMAX; i++) {
		std::string tmp;
		tmp = this->_interface[i].name;
		if (this->_interface[i].ether.empty() == false) {
			tmp += "    ether: ";
			tmp += this->_interface[i].ether;
		}
		if (this->_interface[i].ipv4.empty() == false) {
			tmp += "    ipv4: ";
			tmp += this->_interface[i].ipv4;
		}
		if (this->_interface[i].ipv6.empty() == false) {
			tmp += "    ipv6: ";
			tmp += this->_interface[i].ipv6;
		}
		mvwprintw(this->_subWin, i + 1, 1, tmp.c_str());
	}
}

void NetIfModule::displayQT(void)
{
    this->_update();
	/*
    for (int i=0; i < IFAMAX; i++) {
        _labels[i]->setText(_interface[i].c_str());
    }
	*/
}
