#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->showMessage("Ready");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        loadFile(fileName);
}

void MainWindow::on_actionSave_triggered()
{

}

bool MainWindow::loadFile(QString fileName){
    QFile file(fileName);
    qDebug() << fileName << " is opened";
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream text(&file);
    ui->plainTextEdit->setPlainText(text.readAll());
    file.close();
    return true;
}

bool MainWindow::saveFile(QString fileName){
    QFile file(fileName);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream text(&file);
    text << processedText;
    file.close();
    return true;
}

void MainWindow::on_actionWrite_triggered()
{
    processText();
    QString fileName = QFileDialog::getSaveFileName(this);
    if (!fileName.isEmpty())
        saveFile(fileName);
}

bool MainWindow::processText(){
    processedText.clear();
    QString contents = ui->plainTextEdit->toPlainText();
    QTextStream in(&contents);
    while(!in.atEnd() ){
        QString line = in.readLine();
        QString expandedLine = line.append("\n");
        processedText.append(expandedLine);
    }
    return true;
}

void MainWindow::on_actionTestAll_triggered()
{
    loadFile("C:/Users/Kevin/Desktop/ups.txt");
    on_actionWrite_triggered();

}
