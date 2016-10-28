#include <QApplication>
#include "mainwindow.h"
#include "gtuvos.h"

int main(int argc, char *argv[])
{
    GTUVOS::getInstance();
    QApplication app(argc,argv);

    MainWindow m;
    m.show();
    return app.exec();
}
