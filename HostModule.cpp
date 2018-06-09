/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:46:32 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/09 14:19:25 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostModule.hpp"
#include <unistd.h>

#define BUFF 256

HostModule::HostModule(int posx, int posy):
	MonitorModule(HOSTMOD_X, HOSTMOD_Y, posx, posy)
{
	char hostname[BUFF];
	char username[BUFF];

	gethostname(hostname, BUFF);
	getlogin_r(username, BUFF);

	this->_hostname = hostname;
	this->_hostname = this->_hostname.substr(0, HOSTMOD_X - 2); /* truncate */
	this->_username = username;
	this->_username = this->_username.substr(0, HOSTMOD_X - 2);
};

HostModule::~HostModule(void) {
};

void		HostModule::display(void) {
	mvwprintw(this->_subWin, 1, 1, this->_hostname.c_str());
	mvwprintw(this->_subWin, 2, 1, this->_username.c_str());
};
