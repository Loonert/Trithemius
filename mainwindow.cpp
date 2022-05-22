#include "mainwindow.h"
#include "ui_mainwindow.h"

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



void MainWindow::on_shifr_pushButton_clicked()
{
    for (int w=0; w<26;w++)
    {
        qDebug() <<" bukva "<<alphabet1[w]<< " = " << w;
    }
    int m; int L; QString str; int flag;
    QString initext = ui->shifr_TextEdit->toPlainText();
    for (int i = 0; i < initext.length(); i++)
    {
        if (initext[i].isUpper())
        {
            for (int j = 0; j < ALPHABET2.length(); j++)
            {
                if (initext[i] == ALPHABET2[j])
                {
                    m = j;
                    flag = 0;
                }
            }

        }
        else if (initext[i].isLower())
            {
                for (int j = 0; j < alphabet1.length(); j++)
                {
                    if (initext[i] == alphabet1[j])
                    {
                        m = j;
                        flag = 1;
                    }
                }
            }
        else
        {
            flag = -1;
        }
        int k = A*(i+1) + B;
        qDebug()<<k;
        L = (m + k) % ALPHABET2.length();
        qDebug()<< "L=" << L;
        if (flag == 1)
        {
            str = str + alphabet1[L];
        }
        else if (flag ==0)
        {
            str = str + ALPHABET2[L];
        }
        else if (flag == -1)
        {
            str = str + initext[i];
        }
    }
    ui->output->setPlainText(str);

}


void MainWindow::on_deshifr_pushButton_2_clicked()
{
    int L; int m; QString str; int flag;
    QString initext = ui->deshifr_TextEdit->toPlainText();
    for (int i = 0; i < initext.length(); i++)
    {
        if (initext[i].isUpper())
        {
            for (int j = 0; j < ALPHABET2.length(); j++)
            {
                if (initext[i] == ALPHABET2[j])
                {
                    L = j;
                    flag = 0;
                }
            }

        }
        else if (initext[i].isLower())
            {
                for (int j = 0; j < alphabet1.length(); j++)
                {
                    if (initext[i] == alphabet1[j])
                    {
                        L = j;
                        flag = 1;
                    }
                }
            }
        else
        {
            flag = -1;
        }
        int k = A*(i+1) + B;
     //   qDebug()<<k;
        while ((L-k)<=0)
        {
            L = L + alphabet1.length();
        }
        m = (L - k) % alphabet1.length();
     //   qDebug()<< "L=" << L;
        if (flag == 1)
        {
            str = str + alphabet1[m];
        }
        else if (flag ==0)
        {
            str = str + ALPHABET2[m];
        }
        else if (flag == -1)
        {
            str = str + initext[i];
        }
    }
        ui->output->setPlainText(str);
}
