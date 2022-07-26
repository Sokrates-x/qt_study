#include "dragtabwidget.h"
#include <QtGui>
#include <QPoint>
#include <QApplication>

dragTabWidget::dragTabWidget(QWidget *p)
{
    setAcceptDrops(true);
}

void dragTabWidget::mousePressEvent(QMouseEvent *e) {
   if (e->button() == Qt::LeftButton)
       start_pos_ = e->pos();
    QTableWidget::mousePressEvent(e);
}

void dragTabWidget::mouseMoveEvent(QMouseEvent *e) {
    if (e->buttons() & Qt::RightButton) {
        int distance = (e->pos() - start_pos_).manhattanLength();
        if (distance >= QApplication::startDragDistance())
            performDrag();
    }
    QTableWidget::mouseMoveEvent(e);
}

QString dragTabWidget::selectAsPlainText() {
    QList<QTableWidgetSelectionRange> ranges = selectedRanges();
    int top_ = 9, left_ = 9, bottom_ = 0, right_ = 0;
    for (auto m : ranges) {
       top_ = m.topRow() > top_ ? top_ : m.topRow();
       left_ = m.leftColumn() > left_ ? left_ : m.leftColumn();
       bottom_ = m.bottomRow() < bottom_ ? bottom_ : m.bottomRow();
       right_ = m.rightColumn() < right_ ? right_ : m.rightColumn();
    }
    QString str = "";
    for (int i = top_; i <= bottom_; ++i) {
        if (i > top_)
            str += "\n";
        for (int j = left_; j <= right_; ++j) {
            if (j > left_)
                str += "\t";
            if (item(i, j))
                str += item(i, j)->text();
            else
                str += " ";
        }
    }
    return str;
}

void dragTabWidget::performDrag() {
    QString plain_text = this->selectAsPlainText();
    if (plain_text.isEmpty())
        return;
    QMimeData *mime = new QMimeData;
    mime->setText(plain_text);
    mime->setHtml(to_html(plain_text));
    mime->setData("text/csv", to_csv(plain_text).toUtf8());
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mime);
    if (drag->exec(Qt::CopyAction | Qt::MoveAction) == Qt::MoveAction)
        ;
}

QString dragTabWidget::to_csv(const QString &str) {
    QString res = str;
    res.replace("\\", "\\\\");
    res.replace("\"", "\\\"");
    res.replace("\t", "\", \"");
    res.replace("\n", "\"\n\"");
    res.prepend("\"");
    res.append("\"");
    return res;
}

QString dragTabWidget::to_html(const QString &str) {
    QString res = str;
    res.replace("\t", "<td>");
    res.replace("\n", "\n<tr><td>");
    res.prepend("<table>\n<tr><td>");
    res.append("\n</table>");
    return res;
}

void dragTabWidget::dragMoveEvent(QDragMoveEvent *e) {
    dragTabWidget *s = qobject_cast<dragTabWidget *>(e->source());
    if (s && s != this) {
        e->setDropAction(Qt::MoveAction);
        e->accept();
    }
}

void dragTabWidget::dragEnterEvent(QDragEnterEvent *e) {
    dragTabWidget *s = qobject_cast<dragTabWidget *>(e->source());
    if (s && s != this) {
        e->setDropAction(Qt::MoveAction);
        e->accept();
    }
}

void dragTabWidget::dropEvent(QDropEvent *e) {
    if (e->mimeData()->hasFormat("text/csv")) {
        QByteArray csvd = e->mimeData()->data("text/csv");
        QString csv = QString::fromUtf8(csvd);
        e->acceptProposedAction();
    } else if (e->mimeData()->hasFormat("text/plain")) {
        QString plain = e->mimeData()->text();
        e->acceptProposedAction();
    }
}
