/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetIfModule.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:08:19 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 18:34:01 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NetIfModule_hpp
#define NetIfModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>

#define NETIFMOD_X 95
#define NETIFMOD_Y 15

#define IFAMAX 13 /* max interface represented in module */

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
	/**/
	s_ifa		_interface[IFAMAX];

	uint64_t	_totBytesIn;
	uint64_t	_totBytesOut;

	/**/
	void		_update(void);
	void		_updateNetLoad(void);

public:
	NetIfModule(int posx, int posy);
    NetIfModule(QFrame *);
	~NetIfModule(void);

	/**/
	void		display(void);
     void displayQT(void);
};

#endif
