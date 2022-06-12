#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <cpr/cpr.h>

#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>

#include <nlohmann/json.hpp>
#include <string.h>

#include "wav.h"
#include "ASCIIBreaker.h"
#include <time.h>


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

    nlohmann::json jsonData = nlohmann::json::parse(r.text);
    std::cout << r.text << std::endl;

    // Tests


    if(r.status_code == 200) {
        ui->lineEdit->setText("[SUCCESS]    Wczytano");
    } else ui->lineEdit->setText("[ERROR]   Wystapił bład podczas pobierania nazw.");
}


void MainWindow::on_openFileBtn_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this, "Choose File");


   if(filename.isEmpty())
       return;


   int number = rand() % 90000000 + 10000000;
   std::cout << "OUTPUY NUMBER: " << number << std::endl;

   QFileInfo file(filename);
   QFile fileToCopy(filename);

   // TEMP, only png files
   // todo: delete files from copied folder in order to prevent build failure
   fileToCopy.setFileName(QString::fromStdString(std::to_string(number))+".png");


   QFileInfo newFileInfo(fileToCopy.fileName());
   this->filePath = newFileInfo.filePath();
   this->fileName = fileToCopy.fileName();
   QFile::copy(file.absoluteFilePath(), this->filePath);
   std::cout << "FILEPATH: " << this->filePath.toStdString() << std::endl;
   std::cout << "FILE NAME: " << this->fileName.toStdString() << std::endl;
   ui->lineEdit->setText("[SUCCESS]     Wczytano plik: " + this->filePath);
}


void MainWindow::on_postFileBtn_clicked()
{

    wav wav;

    // send file
    cpr::Response r = cpr::Post(cpr::Url{"https://zaliczeniebackend.azurewebsites.net/api/files"},
                       cpr::Multipart{{"files", cpr::File{this->filePath.toStdString()}}});

    std::cout << r.status_code << std::endl;

    // DEBUG:
    std::cout << r.text << std::endl;

    if(r.status_code == 200) {
        ui->lineEdit->setText("[SUCCESS]    Wysłano plik");
    } else ui->lineEdit->setText("[ERROR]   Wystapił bład podczas wysyłania pliku.");
}


void MainWindow::on_testWAV_clicked()
{
//    wav wav;
//    wav.wavFileCreate();


    setASCIIValue(123456789);
    ASCIIToFrequency();


    std::cout << "hej" << std::endl;
}

