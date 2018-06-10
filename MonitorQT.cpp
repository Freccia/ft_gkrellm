#include "MonitorQT.hpp"
#include "OSModule.hpp"
#include "DateModule.hpp"
#include "HostModule.hpp"
#include "SysModule.hpp"
#include "NetIfModule.hpp"
#include "RamModule.hpp"
#include <iostream>
#include <signal.h>
#include <QApplication>
#include <QtWidgets>
#include <QGraphicsView>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QTimer>
#include <QGridLayout>


MonitorQT::MonitorQT(void) : QWidget(), _timer(new QTimer(this)), _layout(new QGridLayout(this))
{
    QObject::connect(_timer, SIGNAL(timeout(void)), this, SLOT(refreshModules()));
    _timer->start(250);
    _addRamModule();
    _addOsModule();
    _addSysModule();
    _addNetIfModule();
    _addDateModule();
    _addHostfModule();
    this->setLayout(_layout);
    this->_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
};

MonitorQT::~MonitorQT(void)
{

};


/* refresh and display all modules */
void		MonitorQT::refreshModules(void) {
    for (size_t i=0; i < this->_modules.size(); i++) {
        this->_modules[i]->displayQT();
    }
}

QFrame *MonitorQT::_frameBoxedFactory() const
{
    QFrame *frame = new QFrame();
    frame->setFrameShape(QFrame::Box);
    return frame;
}

void MonitorQT::_addRamModule()
{
    QFrame *frame = _frameBoxedFactory();
    _layout->addWidget(frame, 1, 0);
    RamModule *ram = new RamModule(frame);
    _modules.push_back(ram);
    _frames.push_back(frame);
}

void MonitorQT::_addOsModule()
{
    QFrame *frame = _frameBoxedFactory();
    _layout->addWidget(frame, 2, 0);
    OSModule *os = new OSModule(frame);
    _modules.push_back(os);
    _frames.push_back(frame);
}
void MonitorQT::_addSysModule()
{
    QFrame *frame = _frameBoxedFactory();
    _layout->addWidget(frame, 3, 0);
    SysModule *sys = new SysModule(frame);
    _modules.push_back(sys);
    _frames.push_back(frame);
}
void MonitorQT::_addNetIfModule()
{
    QFrame *frame = _frameBoxedFactory();
    _layout->addWidget(frame, 2, 1, 2, 1);
    NetIfModule *net = new NetIfModule(frame);
    _modules.push_back(net);
    _frames.push_back(frame);
}
void MonitorQT::_addDateModule()
{
    QFrame *frame = _frameBoxedFactory();
    _layout->addWidget(frame, 1, 1, 1, 1);
    DateModule *date = new DateModule(frame);
    _modules.push_back(date);
    _frames.push_back(frame);
}
void MonitorQT::_addHostfModule()
{
    QFrame *frame = _frameBoxedFactory();
    _layout->addWidget(frame, 0, 0, 1, 2);
    HostModule *host = new HostModule(frame);
    _modules.push_back(host);
    _frames.push_back(frame);
}

