/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <>                                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:16:45 by lfabbro           #+#    #+#             */
/*   Updated: 2018/06/10 22:16:51 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MonitorModule_hpp
#define MonitorModule_hpp

#include "IMonitorModule.hpp"
#include <ncurses.h>
#include <vector>
#include <iostream>
#include <QFrame>
#include <QLabel>
#include <deque>
#include <QChart>
#include <QtCharts>
#include <QLineSeries>


#define C_X 0
#define C_Y 1

#define STDMONITOR_X 20
#define STDMONITOR_Y 10

class MonitorModule: public IMonitorModule {
protected:
    MonitorModule(void);

    /*				*/
	std::string			_name;
    std::vector<int>	_size;
    std::vector<int>	_pos;
    std::vector<QLabel *> _labels;
    std::deque<double> _percents;
    std::deque<double> _percentsIn;
    std::deque<double> _percentsOut;
    clock_t				_lastDisplay;
    time_t _lastRefresh;
    WINDOW				*_subWin;
    QtCharts::QChart *_chart;
    QtCharts::QChartView *_chartView;
    QValueAxis *_axisX;
    QValueAxis *_axisY;
    std::vector<QtCharts::QLineSeries *> _chartLines;
    QFrame *_frame;
    void _init();

public:
    MonitorModule(int width, int height, int x, int y);
    MonitorModule(int width, int height, int x, int y, std::string name);
    MonitorModule(MonitorModule const &Cc);
    virtual ~MonitorModule(void);
    MonitorModule &operator=(MonitorModule const &Cc);

    /*				*/
    std::vector<int>		getSize(void);
    std::vector<int>		getPos(void);
    void					deleteMe(void);
    void					writeMe(int x, int y, std::string str);
    void					refresh(void);
    /*				*/
    virtual void			display(void);
    //virtual void			update(void);
    virtual void displayQT();
    virtual void displayChart(void);
};

#endif
