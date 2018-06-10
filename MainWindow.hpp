#ifndef CLASS_MAINWINDOW_H
#define CLASS_MAINWINDOW_H
#include <iostream>
#include <string>
#include <QApplication>
#include <QWidget>
#include <QGraphicsView>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>


class MainWindow : public QWidget
{

    Q_OBJECT

public:
  MainWindow(void);
  MainWindow(MainWindow const &rhs);
  ~MainWindow(void);
  MainWindow &operator=(MainWindow const &rhs);

public slots:
  void testUpdate();

private:
  QGraphicsView *_graph;
  QLCDNumber *_lcd;
  QSlider *_slider;
  QProgressBar *_bar;
};
#endif
