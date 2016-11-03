#include <QApplication>
#include "mainwindow.h"
#include "gtuvos.h"

int main(int argc, char *argv[])
{

    QApplication app(argc,argv);
    GTUVOS::getInstance();

    MainWindow m;
    m.show();
    return app.exec();
}
