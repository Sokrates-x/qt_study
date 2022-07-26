#include "draglistwidget.h"
#include <QtGui>
#include <QPoint>
#include <QApplication>

dragListWidget::dragListWidget(QWidget *p) : QListWidget(p)
{
    setAcceptDrops(true);
}

dragListWidget::~dragListWidget()
{

}

void dragListWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        start_point_ = e->pos();
    QListWidget::mousePressEvent(e);
}

void dragListWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton) {
        int distance = (e->pos() - start_point_).manhattanLength();
        if (distance >= QApplication::startDragDistance())
            perfomDrag();
    }
    QListWidget::mouseMoveEvent(e);
}

void dragListWidget::dragEnterEvent(QDragEnterEvent *e)
{
    dragListWidget *s = qobject_cast<dragListWidget *>(e->source());
    if (s && s != this) {
        e->setDropAction(Qt::CopyAction);
        e->accept();
    }
}

void dragListWidget::dragMoveEvent(QDragMoveEvent *e)
{
    dragListWidget *s = qobject_cast<dragListWidget *>(e->source());
    if (s && s != this) {
        e->setDropAction(Qt::CopyAction);
        e->accept();
    }
}

void dragListWidget::dropEvent(QDropEvent *e)
{
    dragListWidget *s = qobject_cast<dragListWidget *>(e->source());
    if (s && s != this) {
        addItem(e->mimeData()->text());
        sortItems();
        e->setDropAction(Qt::CopyAction);
        e->accept();
    }
}

void dragListWidget::perfomDrag()
{
    QListWidgetItem *item = currentItem();
    if (item) {
       QMimeData *mime = new QMimeData;
       mime->setText(item->text());
       QDrag *drag = new QDrag(this);
       drag->setMimeData(mime);
       if (drag->exec(Qt::CopyAction) == Qt::CopyAction) {
           delete item;
           this->sortItems();
       }
    }
}
