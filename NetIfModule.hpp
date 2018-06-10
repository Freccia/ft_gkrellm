/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetIfModule.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:08:19 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/09 15:11:56 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NetIfModule_hpp
#define NetIfModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>

#define NETIFMOD_X 45
#define NETIFMOD_Y 23

#define IFAMAX 20

class NetIfModule: public MonitorModule {
private:
	/**/
	NetIfModule(void);
	NetIfModule(NetIfModule const &Cc);
	NetIfModule &operator=(NetIfModule const &Cc);
	/**/
	std::string		_interface[IFAMAX];

	/**/
	void		_update(void);

public:
	NetIfModule(int posx, int posy);
    NetIfModule(QFrame *);
	~NetIfModule(void);

	/**/
	void		display(void);
     void displayQT(void);
};

#endif
