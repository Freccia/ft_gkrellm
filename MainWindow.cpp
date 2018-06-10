#include <iostream>
#include <string>
#include "MainWindow.hpp"
#include <QApplication>
#include <QWidget>
#include <QGraphicsView>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QTimer>

MainWindow::MainWindow(/*Something*/): QWidget(), _graph(new QGraphicsView(this))
{
    setFixedSize(2000, 1000);
    QTimer *timer = new QTimer(this);

    _lcd = new QLCDNumber(this);

    _lcd->setSegmentStyle(QLCDNumber::Flat);

    _lcd->move(50, 20);

    _slider = new QSlider(Qt::Horizontal, this);

    _slider->setGeometry(10, 80, 150, 20);
    _slider->setMaximum(100);
    _slider->setMinimum(1);
    _lcd->display(_slider->value());
    QObject::connect(_slider, SIGNAL(valueChanged(int)), _lcd, SLOT(display(int)));


    _bar = new QProgressBar(this);

    _bar->setGeometry(10, 50, 150, 30);
    _bar->setValue(_slider->value());
    QObject::connect(_slider, SIGNAL(valueChanged(int)), _bar, SLOT(setValue(int)));

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(testUpdate()));
    timer->start(250);
}

MainWindow::MainWindow(MainWindow const &rhs)
{
    *this = rhs;
}

MainWindow::~MainWindow()
{
    delete this->_graph;
}

MainWindow &MainWindow::operator=(MainWindow const &rhs)
{
    if (static_cast<const void *>(&rhs))
        ;
    return *this;
}

void MainWindow::testUpdate()
{
    std::cout<<"Test Update"<<std::endl;
    _slider->setValue(_slider->value() + 1);
}
