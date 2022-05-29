#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <cpr/cpr.h>

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


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_getListBtn_clicked()
{
    cpr::Response r = cpr::Get(cpr::Url{"https://localhost:5001/api/files"},
                          cpr::Parameters{{"anon", "true"}, {"key", "value"}});
        r.status_code;                  // 200
        r.header["content-type"];       // application/json; charset=utf-8
        r.text;                         // JSON text string

        std::cout << r.status_code << std::endl;
}


void MainWindow::on_openFileBtn_clicked()
{

}


void MainWindow::on_postFileBtn_clicked()
{

}

