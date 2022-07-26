#include "mainwindow.h"
#include <QTextEdit>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    tedit_ = new QTextEdit;
    setCentralWidget(tedit_);
    tedit_->setAcceptDrops(false);
    setAcceptDrops(true);
    setWindowTitle("Text Edit");
}

MainWindow::~MainWindow()
{
}

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasFormat("text/uri-list"))
        e->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *e)
{
    QList<QUrl> urls = e->mimeData()->urls();
    if (urls.isEmpty())
        return;
    QString filename = urls.first().toLocalFile();
    if (filename.isEmpty())
        return;
    if (readFile(filename))
        setWindowTitle(tr("%1 - %2").arg(filename).arg("Drag File"));
}

bool MainWindow::readFile(const QString &s)
{

}
