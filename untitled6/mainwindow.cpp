#include "mainwindow.h"

#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    fileMenu_ = menuBar()->addMenu(tr("&File"));
    QAction *newAction_ = new QAction(tr("New"), this);
    fileMenu_->addAction(newAction_);
    this->show();
}

MainWindow::~MainWindow()
{
}

