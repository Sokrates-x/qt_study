#ifndef DRAGTABWIDGET_H
#define DRAGTABWIDGET_H

#include <QTableWidget>
class QPoint;

class dragTabWidget : public QTableWidget
{
    Q_OBJECT
public:
    dragTabWidget(QWidget *p = nullptr);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);

private:
    void performDrag();
    QString to_html(const QString &);
    QString to_csv(const QString &);
    QString selectAsPlainText();
    QPoint start_pos_;
};

#endif // DRAGTABWIDGET_H
