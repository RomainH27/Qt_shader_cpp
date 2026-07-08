#include "mainwindow.hpp"
#include "glwidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(new GLWidget(this));
}