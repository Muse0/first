#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionWrite_triggered();

    void on_actionTestAll_triggered();

private:
    Ui::MainWindow *ui;
    bool loadFile(QString filename);
    bool processText();
    bool saveFile(QString fileName);
    QString processedText;
};

#endif // MAINWINDOW_H
