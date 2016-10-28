#include <QApplication>
#include "mainwindow.h"
#include "gtuvos.h"


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // get system informations and print on startup
    double version = GTUVOS::getInstance()->getVersion();
    QString name = QString::fromStdString(GTUVOS::getInstance()->getName());
    ui->terminalScreen->insertPlainText("Welcome to "+name+"\n");
    ui->terminalScreen->insertPlainText("Version "+QString::number(version)+"\n");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputBox_returnPressed()
{
    QString command=ui->inputBox->text();//lineEdit'de bulunan degeri aldim.

    bool res = GTUVOS::getInstance()->executeCmd(command.toStdString());

    //QStringList lines =command.split(" ");//Bosluga gore ayirip string list e attim.

    //QMessageBox::information(this,"baslık",QString::number(lines.count()));

    //Bu degeri textBrowser'a yazdim.
    if(res)
        ui->terminalScreen->insertPlainText("cmd success\n");

    //lineEdit'i temizledim.
    ui->inputBox->setText("");
}

