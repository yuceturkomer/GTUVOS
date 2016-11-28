#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <ui_mainwindow.h>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow* getUI(){return ui;}
    ~MainWindow();

    //Key press event listener
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_terminalScreen_cursorPositionChanged();

private:
    Ui::MainWindow *ui;

    QStringList oldInputs;
    int currentInput;

    void textEditEnterPres(); // keyboard enter for evaluate command
    void textEditUPArrowPress(); // keyboard up for prev. command
    void textEditDownArrowPress(); // keyboard down for next command
    void textEditTabArrowPress();
    // sonraki asama olarak tab ile komut tanıma eklenebilir
};

#endif // MAINWINDOW_H
