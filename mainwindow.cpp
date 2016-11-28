#include <QApplication>
#include "mainwindow.h"
#include "gtuvos.h"


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{

    currentInput=0; // input box icin history sırası
    ui->setupUi(this);

    // get system informations and print on startup
    double version = GTUVOS::getInstance()->getVersion();
    QString name = QString::fromStdString(GTUVOS::getInstance()->getName());
    ui->terminalScreen->insertPlainText("Welcome to "+name+"\n");
    ui->terminalScreen->insertPlainText("Version "+QString::number(version)+"\n");
    ui->terminalScreen->insertPlainText("Write 'help' to see all commands""\n");
    ui->terminalScreen->insertPlainText("~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-");
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
void MainWindow::textEditEnterPres()
{

    QString command=ui->inputBox->text();// Get the string from inputBox

    oldInputs.append(command); // komutu hafızaya al
    currentInput=oldInputs.size(); // toplam komut sayisini guncelle
    // her up key geldiginde son komuttan geriye gidicek

    // Res stands for the result. Gets the return value of executeCmd. ExecuteCmd calls the parse function.
    ui->terminalScreen->insertPlainText("\n\n> ");
    GTUVOS::getInstance()->executeCMD(command);

    // Scroll down automatically
    ui->terminalScreen->moveCursor(QTextCursor::End);
    ui->terminalScreen->ensureCursorVisible();

    // Clear the inputBox
    ui->inputBox->clear();
}

/*
 * Keyboard UP-Arrow tusu basildiginda onceki girdiyi ekrana getirir.
 * Girilen input yoksa inputbox temizlenir
 *
*/
void MainWindow::textEditUPArrowPress(){

    if(currentInput<=0){ // ilk yedege geldiyse devam etme
        ui->inputBox->clear();
        return;
    }

    currentInput = currentInput-1;
    ui->inputBox->setText(oldInputs.at(currentInput));
}

/*
 * Keyboard Down-Arrow tusu basildiginda sonraki girdiyi ekrana getirir.
 * Girilen input yoksa inputbox temizlenir
 *
*/
void MainWindow::textEditDownArrowPress(){

    if(currentInput>=oldInputs.size()){ // eger daha once komut girilmediyse islem yapma
        ui->inputBox->clear();
        return;
    }

    ui->inputBox->setText(oldInputs.at(currentInput));
    currentInput = currentInput+1;
}

/*
 * BU fonksiyon input box üzerinde eventlerin kontrolu icin kullanılır
 * Enter girilen komus islenir
 * Arrow tusları ile onceki veya sonraki komutlar gosterilir
*/
void MainWindow::keyPressEvent(QKeyEvent *event){

    switch(event->key()){
        case Qt::Key_Enter:
            textEditEnterPres();
            break;
        case Qt::Key_Return:
            textEditEnterPres();
            break;
        case Qt::Key_Up:
            textEditUPArrowPress();
            break;
        case Qt::Key_Down:
            textEditDownArrowPress();
            break;
        //simdilik default yok
    }

}


void MainWindow::on_terminalScreen_cursorPositionChanged()
{
    // Scroll down automatically
    ui->terminalScreen->moveCursor(QTextCursor::End);
    ui->terminalScreen->ensureCursorVisible();
}
