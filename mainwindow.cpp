#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->lineEdit->clear();
    ui->greetingLabel->clear();
    QObject::connect(ui->lineEdit, SIGNAL(returnPressed()),
                     this, SLOT(greet()));
    //num = n;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_2_clicked(){
    greet();
}

void MainWindow::on_pushButton_clicked(){
    ui->lineEdit->clear();
    ui->greetingLabel->clear();
}

void MainWindow::on_actionQuit_triggered() {
    QApplication::quit();
}

bool MainWindow::isPrime(unsigned int n){
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

void MainWindow::greet() {
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::warning(this, "QHello", "Invalid Input");
        ui->greetingLabel->clear();
        return;
    }
    QString res = ui->lineEdit->text();
    bool ok;
    uint dec = res.toUInt(&ok, 10);
    if(!ok){
        QMessageBox::warning(this, "QHello", "Input is not a number");
        ui->greetingLabel->clear();
        return;
    }
    bool p = isPrime(dec);
    if(p){
        res += " is a prime!";
    }

    else{
        res += " is not a prime!";
    }
    ui->greetingLabel->setText(res);

}
