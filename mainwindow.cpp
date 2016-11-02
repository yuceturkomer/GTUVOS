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
    ui->terminalScreen->insertPlainText("~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n\n");
    ui->terminalScreen->insertPlainText("The available commands are:\n\n help\n cp <file_1> <file_2>\n mail\n\n");
    ui->terminalScreen->insertPlainText("~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-\n\n");

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
 * As the return button is pressed when the inputBox is active, this function will be called.
 *
 * Firstly the text is taken from the inputBox and stored. Then this text is sent
*/
void MainWindow::on_inputBox_returnPressed()
{
    QString command=ui->inputBox->text();// Get the string from inputBox
    QStringList lines = command.split(" ");// Split by space character
    QString commandStr = lines.front(); // First element of list. The command should be here.

    // Res stands for the result. Gets the return value of executeCmd. ExecuteCmd calls the parse function.
    bool res = GTUVOS::getInstance()->executeCmd(command);


    //QMessageBox::information(this,"baslık",QString::number(lines.count()));

    // The > symbol is printed to the terminalScreen
    // Then if executeCmd is true, it prints command's name and a message about function execution being successful.
    // Else prints failure message.
    ui->terminalScreen->insertPlainText("> ");
    if(res){
        ui->terminalScreen->insertPlainText(commandStr);
        ui->terminalScreen->insertPlainText(" command successfully recognized!\n");
    }else{
        ui->terminalScreen->insertPlainText("Failed to recognize the command, please try again or if you want help, just type help and press enter.\n\n");
    }

    // Scroll down automatically
    ui->terminalScreen->moveCursor(QTextCursor::End);
    ui->terminalScreen->ensureCursorVisible();

    // Clear the inputBox
    ui->inputBox->clear();
}

