#include <QApplication>
#include "mainwindow.h"
#include "gtuvos.h"

int main(int argc, char *argv[])
{

    QApplication app(argc,argv);
    MainWindow main;
    GTUVOS::getInstance()->window = main.getUI();

    main.show();
    return app.exec();
}
