/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:34:56 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 18:53:40 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSModule.hpp"
#include <limits.h>
#include <sys/utsname.h>

OSModule::OSModule(int posx, int posy):
	MonitorModule(OSMOD_X, OSMOD_Y, posx, posy)
{
	struct utsname *name = new struct utsname ();

	if (uname(name)) {
		this->_sysname = "Error";
		this->_nodename = "Error";
		this->_release = "Error";
		this->_version = "Error";
		this->_machine = "Error";
	} else {
		this->_sysname = name->sysname;
		this->_nodename = name->nodename;
		this->_release = name->release;
		this->_version = name->version;
		this->_machine = name->machine;
		this->_sysname = this->_sysname.substr(0, OSMOD_X - 2);
		this->_nodename = this->_nodename.substr(0, OSMOD_X - 2);
		this->_release = this->_release.substr(0, OSMOD_X - 2);
		this->_version = this->_version.substr(0, OSMOD_X - 2);
		this->_machine = this->_machine.substr(0, OSMOD_X - 2);
	}
};

OSModule::~OSModule(void) {
};

void		OSModule::display(void) {
	mvwprintw(this->_subWin, 1, 1, this->_sysname.c_str());
	mvwprintw(this->_subWin, 2, 1, this->_nodename.c_str());
	mvwprintw(this->_subWin, 3, 1, this->_release.c_str());
	mvwprintw(this->_subWin, 4, 1, this->_version.c_str());
	mvwprintw(this->_subWin, 5, 1, this->_machine.c_str());
};
