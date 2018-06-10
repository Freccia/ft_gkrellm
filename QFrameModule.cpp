#include <iostream>
#include <string>
#include "QFrameModule.hpp"
#include <QFrame>

QFrameModule::QFrameModule() : QFrame()
{
}

QFrameModule::~QFrameModule()
{
}

void QFrameModule::ShowHidden(void)
{
    if (isVisible())
        hide();
    else
        show();
}
