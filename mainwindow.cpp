#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <cpr/cpr.h>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>

#include <nlohmann/json.hpp>
#include <string.h>

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




void MainWindow::on_getListBtn_clicked()
{
    cpr::Response r = cpr::Get(cpr::Url{"https://zaliczeniebackend.azurewebsites.net/api/files"});


    using json = nlohmann::json;
    std::cout << r.text << std::endl;
}


void MainWindow::on_openFileBtn_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this, "Choose File");


   if(filename.isEmpty())
       return;


   QFileInfo file(filename);
   this->filePath = file.absoluteFilePath();
}


void MainWindow::on_postFileBtn_clicked()
{

    cpr::Response r = cpr::Post(cpr::Url{"https://zaliczeniebackend.azurewebsites.net/api/files"},
                       cpr::Multipart{{"files", cpr::File{this->filePath.toStdString()}}});

    std::cout << r.status_code << std::endl;
    std::cout << r.text << std::endl;
}

