#ifndef CLASS_MAINWINDOW_H
#define CLASS_MAINWINDOW_H
#include <iostream>
#include <string>
#include <QApplication>
#include <QWidget>
#include <QGraphicsView>


class MainWindow : public QWidget
{
public:
  MainWindow(void);
  MainWindow(MainWindow const &rhs);
  ~MainWindow(void);
  MainWindow &operator=(MainWindow const &rhs);

private:
  QGraphicsView *_graph;
};
#endif
