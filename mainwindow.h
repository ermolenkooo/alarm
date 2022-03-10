#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLCDNumber"
#include "QSpinBox"
#include "QCheckBox"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void alarm();

private:
    Ui::MainWindow *ui;
    QSpinBox* spinBox1;
    QSpinBox* spinBox2;
    QCheckBox* checkBox;
    QLCDNumber* clock;
};

#endif // MAINWINDOW_H
