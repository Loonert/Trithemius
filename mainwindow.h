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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_shifr_pushButton_clicked();

    void on_deshifr_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    int A = 1; int B = 1; int C = 1;
    QString alphabet1 = "abcdefghijklmnopqrstuvwxyz";
    QString ALPHABET2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};
#endif // MAINWINDOW_H
