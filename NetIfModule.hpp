/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetIfModule.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:08:19 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/24 23:45:36 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NetIfModule_hpp
#define NetIfModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>

#define NETIFMOD_X 95
#define NETIFMOD_Y 15

#define IFAMAX 13 /* max interface represented in module */

/* network interface structure */
struct s_ifa {
	std::string		name;
	std::string		ether;
	std::string		ipv4;
	std::string		ipv6;
};

class NetIfModule: public MonitorModule {
private:
	/**/
	NetIfModule(void);
	NetIfModule(NetIfModule const &Cc);
	NetIfModule &operator=(NetIfModule const &Cc);

	/* Methods */
	void		_update(void);
	void		_updateNetLoad(void);

	/* Attributes */
	s_ifa		_interface[IFAMAX];
	uint64_t	_totBytesIn;
	uint64_t	_totBytesOut;

public:
	NetIfModule(int posx, int posy);
    NetIfModule(QFrame *);
    virtual ~NetIfModule(void);

	/* Methods */
	void		display(void);
	void		displayQT(void);
	void		displayChart(void);
};

#endif
