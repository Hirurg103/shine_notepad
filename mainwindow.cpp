#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "central.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    central = new Central();
    setCentralWidget(central);
    setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete central;
}
