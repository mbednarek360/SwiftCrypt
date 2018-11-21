#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QProcess>

QString fileName = "";
bool encrypt = true;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fileButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
        tr("Select file."));
    if (fileName != "") {
        QString fName = fileName.section("/",-1,-1);
        if (fileName.right(3) == ".sc") {
            ui->startButton->setText("Decrypt");
            encrypt = false;
        }
        else {
            ui->startButton->setText("Encrypt");
            encrypt = true;
        }
        ui->progressBox->setText("File: " + fName);
    }

}

void MainWindow::on_startButton_clicked()
{
    QString key = ui->keyInp->text();
    if (fileName != "") {
        if (key != "") {
        QString commandString = ("../../out/encrypt \"" + fileName + "\" ../../tmp/key ");
        if (encrypt) {
            commandString += "-e";
        }
        else {
            commandString += "-d";
        }


        QFile file("../../tmp/key");
            if (file.open(QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << key << endl;
            }


         if (encrypt) {
              ui->progressBox->append("Encrypting file...");
         }
         else {
              ui->progressBox->append("Decrypting file...");
         }
        ui->progressBox->repaint();


        QProcess process;
        process.setProcessChannelMode(QProcess::MergedChannels);
        process.start(commandString);
        process.waitForFinished(-1);
        file.remove();
        QString outp = process.readAllStandardOutput();
        if (outp.right(3) == "..\n") {
            fileName = "";
            if (encrypt) {
                ui->progressBox->setText("Finished encryption.");
            }
            else {
                ui->progressBox->setText("Finished decryption.");
            }
        }
        else {
            ui->progressBox->setText("Error decrypting! Please check your password.");
        }

    }
    else {
        QMessageBox::critical(this, tr("Error"), tr("Please type a valid password!"), QMessageBox::Ok);
        }
    }
    else {
        QMessageBox::critical(this, tr("Error"), tr("Please upload a file first!"), QMessageBox::Ok);
    }
}
