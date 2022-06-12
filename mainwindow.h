#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//    var
    QString filePath;
    QString fileName;
    QLineEdit *logMessage = new QLineEdit();

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_getListBtn_clicked();

    void on_openFileBtn_clicked();

    void on_postFileBtn_clicked();

    void on_testWAV_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
