#include <iostream>
#include <string>
#include "MainWindow.hpp"
#include <QApplication>
#include <QWidget>
#include <QGraphicsView>


MainWindow::MainWindow(/*Something*/): QWidget(), _graph(new QGraphicsView(this))
{
    this->setFixedSize(2000, 1000);
    this->_graph->setGeometry(0, 0, 500, 20);
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
