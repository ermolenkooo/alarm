#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLCDNumber"
#include "QSpinBox"
#include "QCheckBox"
#include "QGridLayout"
#include "QTimer"
#include "QTime"
#include "QLabel"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString stl = "background-color: lemonchiffon; font-size: 14pt";
    setStyleSheet(stl);
    QString stl1 = "background-color: white";

    setWindowTitle(tr("будильник"));
    spinBox1 = new QSpinBox();
    spinBox2 = new QSpinBox();
    spinBox1->setStyleSheet(stl1);
    spinBox2->setStyleSheet(stl1);

    clock = new QLCDNumber();
    clock->setStyleSheet(stl1);
    checkBox = new QCheckBox();
    spinBox1->setMaximum(0);
    spinBox1->setMaximum(23);
    spinBox2->setMaximum(0);
    spinBox2->setMaximum(59);

    QTime time = QTime::currentTime();
    spinBox1->setValue(time.hour());
    spinBox2->setValue(time.minute());
    QLabel* l1 = new QLabel;
    QLabel* l2 = new QLabel;
    l1->setText("включить будильник:");
    l2->setText("установить нужное время: ");
    QGridLayout* glayout = new QGridLayout();
    glayout->addWidget(clock, 0, 0, 1, 3);
    glayout->addWidget(l2, 1, 0);
    glayout->addWidget(spinBox1, 1, 1);
    glayout->addWidget(spinBox2, 1, 2);
    glayout->addWidget(l1, 2, 0);
    glayout->addWidget(checkBox, 2, 1);

    QWidget* wdg = new QWidget();
    wdg->setLayout(glayout);

    this->setCentralWidget(wdg);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(alarm()));
    timer->start(1000);
}

void MainWindow::alarm()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    clock->display(text);

    if (checkBox->isChecked())
       if (time.hour() == spinBox1->value() && time.minute() == spinBox2->value())
       {
         QMessageBox mes;
         QString stl = "font-size: 14pt";
         mes.setStyleSheet(stl);
         mes.setText("вы хотели что-то сделать? время пришло!");
         mes.setWindowTitle("будильник");
         mes.setStandardButtons(QMessageBox::Ok);
         mes.setDefaultButton(QMessageBox::Ok);
         int result=mes.exec();
         if(result== QMessageBox::Ok)
         {
            checkBox->setChecked(false);
            spinBox1->setValue(time.hour());
            spinBox2->setValue(time.minute());
         }
       }
}

MainWindow::~MainWindow()
{
    delete ui;
}

