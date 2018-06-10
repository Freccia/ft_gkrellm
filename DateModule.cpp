/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:44:59 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 20:55:18 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateModule.hpp"
#include <QBoxLayout>
#include <QRect>
#include <QFrame>

DateModule::DateModule(QFrame *fr):
    MonitorModule(DATEMOD_X, DATEMOD_Y, 0, 0)
{
    _frame = fr;
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom, _frame);

    layout->setSizeConstraint(QLayout::SetMinimumSize);
    QLabel *l1 = new QLabel(_frame);

    _labels.push_back(l1);

    layout->addWidget(l1);
    _frame->setLayout(layout);
}

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
	this->_date = this->_date.substr(0, DATEMOD_X - 4);
}

void		DateModule::display(void) {
	this->update();
	mvwprintw(this->_subWin, 1, 2, this->_date.c_str());
}

void DateModule::displayQT(void)
{
    this->update();
    this->_labels[0]->setText(_date.c_str());
}
