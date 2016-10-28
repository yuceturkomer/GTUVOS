#include "mainwindow.h"
#include "qmessagebox.h"
#include "gtuvos.h"


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // get system informations and print on startup
    double version = GTUVOS::getInstance()->getVersion();
    QString name = QString::fromStdString(GTUVOS::getInstance()->getName());
    ui->textBrowser->insertPlainText("Welcome to "+name+"\n");
    ui->textBrowser->insertPlainText("Version "+QString::number(version)+"\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString gelenDeger=ui->lineEdit->text();//lineEdit'de bulunan degeri aldim.

    bool res = GTUVOS::getInstance()->executeCmd(gelenDeger.toStdString());

    QStringList lines =gelenDeger.split(" ");//Bosluga gore ayirip string list e attim.


    //QMessageBox::information(this,"baslık",QString::number(lines.count()));

    //Bu degeri textBrowser'a yazdim.
    if(res)
        ui->textBrowser->insertPlainText("cmd success\n");

    //lineEdit'i temizledim.
    ui->lineEdit->setText("");
}
