#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//    var
    QString filePath;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_getListBtn_clicked();

    void on_openFileBtn_clicked();

    void on_postFileBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
