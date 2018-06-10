/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:32:15 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 18:53:30 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSModule_hpp
#define OSModule_hpp

#include "MonitorModule.hpp"
#include <QFrame>

#define OSMOD_X 62
#define OSMOD_Y 7

#define MAXHOSTNAME 256

class OSModule: public MonitorModule {
private:
	/**/
	OSModule(void);
	OSModule(OSModule const &Cc);
	OSModule &operator=(OSModule const &Cc);
	/**/
	std::string		_sysname;
	std::string		_nodename;
	std::string		_release;
	std::string		_version;
	std::string		_machine;
    void _init();

public:
	//OSModule(int width, int height, int x, int y);
	OSModule(int posx, int posy);
    OSModule(QFrame *);
	~OSModule(void);

	/**/
	void		display(void);
    void displayQT(void);
};

#endif
