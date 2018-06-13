/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:44:59 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/13 19:08:10 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateModule.hpp"
#include <QBoxLayout>
#include <QRect>
#include <QFrame>

DateModule::DateModule(QFrame *fr):
    MonitorModule(DATEMOD_X, DATEMOD_Y, 0, 0, "date", "  Date  ")
{
    _frame = fr;
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom, _frame);

    QLabel * title = new QLabel(_name.c_str());
    layout->addWidget(title);
    layout->setSizeConstraint(QLayout::SetMinimumSize);
    QLabel *l1 = new QLabel(_frame);

    _labels.push_back(l1);

    layout->addWidget(l1);
    _frame->setLayout(layout);
}

DateModule::DateModule(int posx, int posy):
	MonitorModule(DATEMOD_X, DATEMOD_Y, posx, posy, "date", "  Date  ") {
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

	int x = 2;
	int y = -1;
	box(this->_subWin, '|', '-');
	mvwprintw(this->_subWin, ++y, x, this->_title.c_str());
	mvwprintw(this->_subWin, ++y, x, this->_date.c_str());
}

void DateModule::displayQT(void)
{
    this->update();
    this->_labels[0]->setText(_date.c_str());
}
