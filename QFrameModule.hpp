#ifndef CLASS_QFRAMEMODULE_H
#define CLASS_QFRAMEMODULE_H
#include <iostream>
#include <string>
#include <QFrame>
#include <QApplication>

class QFrameModule : public QFrame
{

  Q_OBJECT
public:
  QFrameModule(void);
  virtual ~QFrameModule(void);

private:
  QFrameModule(QFrameModule const &rhs);
  QFrameModule &operator=(QFrameModule const &rhs);


public slots:
  void ShowHidden(void);

};
#endif
