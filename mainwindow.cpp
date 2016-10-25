#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include <cstring>
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

    QString gelenDeger=ui->lineEdit->text();
    QStringList lines =gelenDeger.split(" ");


    QMessageBox::information(this,"baslık",QString::number(lines.count()));
    ui->textBrowser->insertPlainText(QString::number(lines.count()));
    // ui->textBrowser->setText(Satir0+" fonksiyonuma "+Satir1+" parametresi gonderiliyor\n");
    ui->lineEdit->setText("");
}
