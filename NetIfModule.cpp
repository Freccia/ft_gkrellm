/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetIfModule.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:37:22 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/13 19:09:05 by lfabbro          ###   ########.fr       */
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
#include <QChart>
#include <QLineSeries>
#include <QChartView>

#define BUFF 256

/* to convert a number to hex (string) */
std::string c2hex(unsigned char c);


NetIfModule::NetIfModule(QFrame *fr) :
    MonitorModule(NETIFMOD_X, NETIFMOD_Y, 0, 0, "net", "  Net Interfaces  ")
{
     _chart = NULL;
    _frame = fr;
    int i = IFAMAX + 1;
    _frame = fr;
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom, _frame);

    QLabel * title = new QLabel(_name.c_str());
    layout->addWidget(title);
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
	MonitorModule(NETIFMOD_X, NETIFMOD_Y, posx, posy, "net",
					"  Net Interfaces  ")
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


void		NetIfModule::display(void)
{
	this->_update();

	box(this->_subWin, '|', '-');
	int x = 2;
	int y = -1;
	mvwprintw(this->_subWin, ++y, x, this->_title.c_str());

	std::string		tmp;
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
		mvwprintw(this->_subWin, ++y, x, tmp.c_str());
	}
	++y;
	tmp = "totBytesIn: ";
	tmp += std::to_string(this->_totBytesIn);
	tmp += "  totBytesOut: ";
	tmp += std::to_string(this->_totBytesOut);
	mvwprintw(this->_subWin, ++y, x, tmp.c_str());
}

void NetIfModule::displayQT(void)
{
    this->_update();
     std::string		tmp;
    int i = 0;
    int j = 0;
    for (i = 0; i < IFAMAX; i++) {
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
        _labels[i]->setText(tmp.c_str());
        j = ++i;
    }
    tmp = "Total bytes in: ";
    tmp += std::to_string(this->_totBytesIn);
    tmp += " Total bytes out: ";
    tmp += std::to_string(this->_totBytesOut);
    _labels[j]->setText(tmp.c_str());
}

void NetIfModule::displayChart(void)
{
    if (!_chart)
    {
        QLayout * layout =  _frame->layout();
        _chart = new QChart();
        _chart->setTitle("Network Usage");
        _axisX = new QValueAxis;
        _axisY = new QValueAxis;
        QChartView *chartView = new QChartView(_chart);
        chartView->setGeometry(20, 300, 600, 600);
        chartView->setRenderHint(QPainter::Antialiasing);
        layout->addWidget(chartView);
    } else
    {
        _chart->removeAllSeries();
        int i = _chartLines.size();
        while (i --> 0)
            delete _chartLines[i];
    }
    if (_percentsIn.size() > 30)
        _percentsIn.pop_front();
    if (_percentsOut.size() > 30)
        _percentsOut.pop_front();
    this->_percentsIn.push_back(_totBytesIn);
    this->_percentsOut.push_back(_totBytesOut);
    QtCharts::QLineSeries *l1 = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *l2 = new QtCharts::QLineSeries();
    l1->setName("Input");
    l2->setName("Output");
    int j;
    if ((j = _percentsIn.size()) > 1)
    {
        int i = 0;
        j--;
        while (i++ < j)
            l1->append(i, _percentsIn[i] - _percentsIn[i - 1]);
    }
    if ((j = _percentsOut.size()) > 1)
    {
        int i = 0;
        j--;
        while (i++ < j)
            l2->append(i, _percentsOut[i] - _percentsOut[i - 1]);
    }
    _chart->addSeries(l1);
    _chart->addSeries(l2);
    _chart->createDefaultAxes();
    _chart->axisX()->setTitleText("Seconds");
    _chart->axisY()->setTitleText("Data amount");
    return;
}
