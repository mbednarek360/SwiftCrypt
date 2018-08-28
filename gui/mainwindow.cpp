#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qprocess.h"
#include "qdebug.h"
#include <QCoreApplication>
#include <QtConcurrent/QtConcurrent>
#include <QFile>
#include <QTextStream>
#include "../../src/infint.h"
#include "../../src/base64.h"
#include "../../src/sha256.h"

QProcess proc;
bool active = false;
bool encrypt = true;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    proc.setProcessChannelMode(QProcess::MergedChannels);
    this->setFixedSize(QSize(720, 295));
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    proc.kill();
    delete ui;
}



void MainWindow::endC() {
    //qDebug() << active << endl;
    if (!active) {


   QtConcurrent::run(this, &MainWindow::crypt);

}
    else {
        qDebug() << "dunzo" << endl;
        ui->radio1->setDisabled(false);
        ui->radio2->setDisabled(false);
        if (encrypt) {
            ui->startButton->setText("Encrypt");
        }
        else {
            ui->startButton->setText("Decrypt");
        }
    }
    active = false;

}


void MainWindow::crypt() {
    active = true;
    ui->startButton->setText("Cancel");
    ui->radio1->setDisabled(true);
    ui->radio2->setDisabled(true);
    ui->startButton->repaint();
    ui->radio1->repaint();
    ui->radio2->repaint();

    SHA256 sha256;
    QString inp = ui->inputEdit->toPlainText();
    QString key = QString::fromStdString(sha256((ui->keyEdit->text()).toStdString()));
    qDebug() << key << endl;


    QString inHex;
    if (encrypt) {
        inHex = inp.toLatin1().toHex();
    }
    else {
        inHex = inp;
    }


    try {
        QFile file("../../tmp/out");
            file.remove();
            file.close();
    } catch (int e) {}


    try {
        QFile file("../../tmp/inp");
            file.remove();
            file.close();
    } catch (int e) {}

        QFile file("../../tmp/inp");
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << inHex << endl;
        }
        file.close();

        try {
            QFile file("../../tmp/key");
                file.remove();
                file.close();
        } catch (int e) {}

            QFile file1("../../tmp/key");
            if (file1.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file1);
                stream << key << endl;
            }

        file1.close();




    QString exec;
    if (encrypt) {
        exec = "../../out/encrypt ../../tmp/inp ../../tmp/key ../../tmp/out -e";

    }
    else {
        exec = "../../out/encrypt ../../tmp/inp ../../tmp/key ../../tmp/out -d";
    }
    proc.start(exec);
    proc.waitForFinished();
    proc.kill();
    QFile outFile("../../tmp/out");
    QString outHex;
    if (outFile.open(QIODevice::ReadWrite)) {
        outHex = outFile.readLine();
    }


    QString outp;
    if (!encrypt) {
            QByteArray text = QByteArray::fromHex(outHex.toUtf8());
            outp = text.data();
    }
    else {
            outp = outHex;
    }
    ui->outputArea->setPlainText(outp);



    MainWindow::endC();
    return;

}

void MainWindow::on_startButton_clicked()
{
    endC();

}

void MainWindow::on_radio1_toggled(bool checked)
{
    encrypt = checked;
    if (encrypt) {
        ui->startButton->setText("Encrypt");
    }
    else {
        ui->startButton->setText("Decrypt");
    }
}
