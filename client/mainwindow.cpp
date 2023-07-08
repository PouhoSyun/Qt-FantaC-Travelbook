#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    setWindowTitle("主页面");
}

mainWindow::~mainWindow()
{
    delete ui;
}
