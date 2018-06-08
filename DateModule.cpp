/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:44:59 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/08 18:02:48 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateModule.hpp"

DateModule::DateModule(int posx, int posy):
	MonitorModule(DATEMOD_X, DATEMOD_Y, posx, posy) {
}

DateModule::~DateModule(void) {
}

void		DateModule::update(void) {
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	this->_date = asctime (timeinfo);
	this->_date = this->_date.substr(0, DATEMOD_X - 2);
}

void		DateModule::display(void) {
	this->update();
	mvwprintw(this->_subWin, 1, 1, this->_date.c_str());
}
