#ifndef DRAGLISTWIDGET_H
#define DRAGLISTWIDGET_H

#include <QListWidget>

class QPoint;

class dragListWidget : public QListWidget
{
    Q_OBJECT

public:
    dragListWidget(QWidget *p = nullptr);
    ~dragListWidget();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *);

private:
    void perfomDrag();

    QPoint start_point_;
};

#endif // DRAGLISTWIDGET_H
