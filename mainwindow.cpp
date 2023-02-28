#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
extern "C" {
#include "log.h"
}
static uint32_t counter = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    counter++;
    ui->label->setText(std::to_string(counter).c_str());
    LOG_INFO("aq1");
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Dims", "Warning", QMessageBox::Yes | QMessageBox::No);
    counter = reply == QMessageBox::Yes ? counter + 1 : counter - 1;
    ui->label->setText(std::to_string(counter).c_str());
    qDebug() << "Counter: " << std::to_string(counter).c_str();
}

