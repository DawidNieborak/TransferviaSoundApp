#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <cpr/cpr.h>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>

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
    cpr::Response r = cpr::Get(cpr::Url{"http://www.httpbin.org/get"},
                          cpr::Parameters{{"filename", "true"}});
        r.status_code;                  // 200
        r.header["content-type"];       // application/json; charset=utf-8
        r.text;                         // JSON text string

//        Json j = Json::parse(r.text);
//        string xx = j["filename"];
//        std::cout << xx << std::endl;
}


void MainWindow::on_openFileBtn_clicked()
{
//    QString fileContent;

    QString filename= QFileDialog::getOpenFileName(this, "Choose File");


   if(filename.isEmpty())
       return;

   QFile file(filename);

   if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
       return;

   QTextStream in(&file);

   this->fileContent= in.readAll();

   file.close();
}


void MainWindow::on_postFileBtn_clicked()
{
    cpr::Response r = cpr::Post(cpr::Url{"https://localhost:5001/api/files"},
                       cpr::Multipart{{"files", cpr::File{"~/Desktop/Screenshot 2021-04-30 at 12.48.33.png"}},
                                      {"files", cpr::File{"~/Desktop/Screenshot 2021-04-30 at 12.48.33.png"}}});
    std::cout << r.status_code << std::endl;
    std::cout << r.text << std::endl;
}

