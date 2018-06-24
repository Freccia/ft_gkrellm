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
#include <QMainWindow>
#include <QGraphicsView>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QTimer>
#include <QGridLayout>
#include <QPushButton>
#include <QToolBar>
#include <QAction>
#include "QFrameModule.hpp"
#include <QIcon>


MonitorQT::MonitorQT(void) :
	QMainWindow(),
	_timerModules(new QTimer(this)),
	_timerCharts(new QTimer(this)),
	_layout(new QGridLayout(this))
{
	QObject::connect(_timerModules, SIGNAL(timeout(void)), this, SLOT(refreshModules()));
	QWidget *w = new QWidget(this);
	setGeometry(0, 0, 2000, 1300);
	_timerModules->start(250);

	QObject::connect(_timerCharts, SIGNAL(timeout(void)), this, SLOT(refreshCharts()));
	_timerCharts->start(1000);

	_addRamModule();
	_addOsModule();
	_addSysModule();
	_addNetIfModule();
	_addDateModule();
	_addHostfModule();
	w->setLayout(_layout);
	this->setCentralWidget(w);
	this->_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
	_setToolBar();
};

MonitorQT::~MonitorQT(void){
};


void MonitorQT::_setToolBar()
{
	QAction *aOs = new QAction("Os", this);
	QAction *aNetIf = new QAction("Network", this);
	QAction *aHost = new QAction("Host", this);
	QAction *aDate = new QAction("Date", this);
	QAction *aCpu = new QAction("CPU", this);
	QAction *aRam = new QAction("RAM", this);
	QToolBar * tb = addToolBar("Toolbar");

	aOs->setIcon(QIcon("images/os_module.png"));
	aNetIf->setIcon(QIcon("images/netIf_module.png"));
	aHost->setIcon(QIcon("images/host_module.png"));
	aDate->setIcon(QIcon("images/date_module.png"));
	aCpu->setIcon(QIcon("images/cpu_module.png"));
	aRam->setIcon(QIcon("images/ram_module.png"));
	tb->addAction(aOs);
	tb->addAction(aNetIf);
	tb->addAction(aHost);
	tb->addAction(aDate);
	tb->addAction(aCpu);
	tb->addAction(aRam);
	_frames[1]->ShowHidden();
	QObject::connect(aOs, SIGNAL(triggered(void)), _frames[1], SLOT(ShowHidden(void)));
	QObject::connect(aNetIf, SIGNAL(triggered(void)), _frames[3], SLOT(ShowHidden(void)));
	QObject::connect(aHost, SIGNAL(triggered(void)), _frames[5], SLOT(ShowHidden(void)));
	QObject::connect(aDate, SIGNAL(triggered(void)), _frames[4], SLOT(ShowHidden(void)));
	QObject::connect(aCpu, SIGNAL(triggered(void)), _frames[2], SLOT(ShowHidden(void)));
	QObject::connect(aRam, SIGNAL(triggered(void)), _frames[0], SLOT(ShowHidden(void)));
}

/* refresh and display all modules */
void			MonitorQT::refreshModules(void) {
	for (size_t i=0; i < this->_modules.size(); i++) {
		this->_modules[i]->displayQT();
	}
}

void			MonitorQT::refreshCharts(void) {
	_modules[3]->displayChart();
	_modules[0]->displayChart();
}

QFrameModule	*MonitorQT::_frameBoxedFactory() const
{
	QFrameModule *frame = new QFrameModule();
	frame->setFrameShape(QFrameModule::Box);
	return frame;
}

void			MonitorQT::_addRamModule()
{
	QFrameModule *frame = _frameBoxedFactory();
	_layout->addWidget(frame, 0, 0, 2, 2);
	RamModule *ram = new RamModule(frame);
	_modules.push_back(ram);
	_frames.push_back(frame);
}

void			MonitorQT::_addOsModule()
{
	QFrameModule *frame = _frameBoxedFactory();
	_layout->addWidget(frame, 2, 0, 2, 2);
	OSModule *os = new OSModule(frame);
	_modules.push_back(os);
	_frames.push_back(frame);
}
void			MonitorQT::_addSysModule()
{
	QFrameModule *frame = _frameBoxedFactory();
	_layout->addWidget(frame, 4, 0, 2, 2);
	SysModule *sys = new SysModule(frame);
	_modules.push_back(sys);
	_frames.push_back(frame);
}
void MonitorQT::_addNetIfModule()
{
	QFrameModule *frame = _frameBoxedFactory();
	_layout->addWidget(frame, 0, 3, 10, 2);
	NetIfModule *net = new NetIfModule(frame);
	_modules.push_back(net);
	_frames.push_back(frame);
}
void MonitorQT::_addDateModule()
{
	QFrameModule *frame = _frameBoxedFactory();
	_layout->addWidget(frame, 6, 0, 1, 1);
	DateModule *date = new DateModule(frame);
	_modules.push_back(date);
	_frames.push_back(frame);
}
void MonitorQT::_addHostfModule()
{
	QFrameModule *frame = _frameBoxedFactory();
	_layout->addWidget(frame, 6, 1, 1, 1);
	HostModule *host = new HostModule(frame);
	_modules.push_back(host);
	_frames.push_back(frame);
}

