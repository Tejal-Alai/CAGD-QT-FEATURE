#include "stdafx.h"
#include "Visualizer.h"

#include <QtWidgets/QApplication>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 
    Visualizer mw;
    mw.show();

    return a.exec();
}  
