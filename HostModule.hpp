/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:17:07 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 18:53:03 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HostModule_hpp
#define HostModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>
#include <QBoxLayout>
#include <QRect>

#define HOSTMOD_X 15
#define HOSTMOD_Y 4

class HostModule: public MonitorModule {
private:
	/**/
	HostModule(void);
	HostModule(HostModule const &Cc);
	HostModule &operator=(HostModule const &Cc);
	/**/
	std::string		_hostname;
	std::string		_username;
    void _init();

public:
	//HostModule(int width, int height, int x, int y);
	HostModule(int posx, int posy);
    HostModule(QFrame *fr);
	~HostModule(void);

	/**/
	void		display(void);
    void displayQT(void);
};

#endif
