/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetIfModule.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:37:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 18:36:08 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetIfModule.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <arpa/inet.h>
#include <netinet/in.h> 
#include <net/route.h>
#include <net/if_dl.h>
#include <net/if.h>
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


void		NetIfModule::_updateNetLoad(void) {
	int		mib[] = {CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST2, 0};
	size_t	size;

	if (sysctl(mib, 6, NULL, &size, NULL, 0) < 0) {
		return;
	}
	char	buf[size];
	if (sysctl(mib, 6, buf, &size, NULL, 0) < 0) {
		return;
	}
	char		*lim = buf + size;
	char		*next = NULL;

	this->_totBytesIn = 0;
	this->_totBytesOut = 0;

	next = buf;
	while (next < lim) {
		struct if_msghdr	*ifm = (struct if_msghdr*)next;
		next += ifm->ifm_msglen;
		if (ifm->ifm_type == RTM_IFINFO2) {
			struct if_msghdr2	*ifm2 = (struct if_msghdr2*)ifm;
			this->_totBytesIn += ifm2->ifm_data.ifi_ibytes;
			this->_totBytesOut += ifm2->ifm_data.ifi_obytes;
		}
	}
}


void		NetIfModule::_update(void) {

	this->_updateNetLoad();

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
	std::string tmp;
	for (int i=0; i < IFAMAX; i++) {
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
	tmp = "totBytesIn: ";
	tmp += std::to_string(this->_totBytesIn);
	tmp += "  totBytesOut: ";
	tmp += std::to_string(this->_totBytesOut);
	mvwprintw(this->_subWin, 13, 1, tmp.c_str());
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
