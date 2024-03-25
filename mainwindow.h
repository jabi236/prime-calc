#ifndef QHELLO_MAINWINDOW_H
#define QHELLO_MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

    //unsigned int num;

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_actionQuit_triggered();

    bool isPrime(unsigned int n);

    void greet();

private:
    Ui::MainWindow* ui;
};


#endif //QHELLO_MAINWINDOW_H
