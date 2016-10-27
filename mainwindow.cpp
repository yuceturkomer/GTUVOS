#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{

    QString gelenDeger=ui->lineEdit->text();//lineEdit'de bulunan degeri aldim.
    QStringList lines =gelenDeger.split(" ");//Bosluga gore ayirip string list e attim.


    //message box'a suanlik lineEdit in kac kelimeden olustugunu aldim.
    QMessageBox::information(this,"baslık",QString::number(lines.count()));

    //Bu degeri textBrowser'a yazdim.
    ui->textBrowser->insertPlainText(QString::number(lines.count())+"\n");

    //lineEdit'i temizledim.
    ui->lineEdit->setText("");
}
