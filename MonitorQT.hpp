#ifndef MonitorQT_hpp
#define MonitorQT_hpp

#include "IMonitorDisplay.hpp"
#include "MonitorModule.hpp"
#include <time.h>
#include <QApplication>
#include <QWidget>
#include <QGraphicsView>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QTimer>
#include <QGridLayout>
#include <QMainWindow>
#include "QFrameModule.hpp"


#define WINBOX_X 0
#define WINBOX_Y 0
#define MINWIN_Y 50
#define MINWIN_X 30

#define WCOLS getmaxy(stdscr)
#define WLINES getmaxx(stdscr)

class MonitorQT: public QMainWindow, public IMonitorDisplay {

    Q_OBJECT

private:
    MonitorQT(MonitorQT const &Cc);
    MonitorQT &operator=(MonitorQT const &Cc);

    std::vector<MonitorModule*> _modules;
    std::vector<QFrameModule*> _frames;
    QTimer *_timerModules;
    QTimer *_timerCharts;
    QGridLayout *_layout;
    QFrameModule *_frameBoxedFactory() const;

    void _addRamModule();
    void _addOsModule();
    void _addSysModule();
    void _addNetIfModule();
    void _addDateModule();
    void _addHostfModule();

    void _setToolBar(void);

public:
    MonitorQT(void);
    virtual ~MonitorQT(void);
    WINDOW		*_win;

public slots:
    void			refreshModules(void);
    void			refreshCharts(void);


};

#endif
