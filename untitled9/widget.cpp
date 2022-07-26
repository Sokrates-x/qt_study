#include "widget.h"
#include <QPaintEvent>
#include <QPainter>
#include <QRect>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    pen_color_ = Qt::black;
    zoom_ = 20;

    image_ = QImage(16, 16, QImage::Format_ARGB32);
    image_.fill(qRgba(0, 0, 0, 0));
}

Widget::~Widget()
{
    image_.save("./icon.jpg");
}

QSize Widget::sizeHint() const
{
    QSize size = zoom_ * image_.size();
    if (zoom_ >= 3)
    {
        size += QSize(1, 1);
    }
    return size;
}

void Widget::setImagePixel(const QPoint &p, bool b)
{
    int i = p.x() / zoom_;
    int j = p.y() / zoom_;
    if (image_.rect().contains(i, j)) {
        if (b) {
            image_.setPixel(i, j, penColor().rgba());
        } else {
            image_.setPixel(i, j, qRgba(0, 0, 0, 0));
        }
        update(pixelRect(i, j));
    }
}

QRect Widget::pixelRect(int i, int j)
{
    if (zoom_ >= 3)
        return QRect(zoom_*i + 1, zoom_*j + 1, zoom_ - 1, zoom_ - 1);
    else
        return QRect(zoom_*i, zoom_*j, zoom_, zoom_);
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        setImagePixel(e->pos(), true);
    } else if (e->button() == Qt::RightButton){
        setImagePixel(e->pos(), false);
    }
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton){
        setImagePixel(e->pos(), true);
    } else if (e->buttons() & Qt::RightButton) {
        setImagePixel(e->pos(), false);
    }
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if (zoom_ >= 3) {
        painter.setPen(palette().color(QPalette::WindowText));
        for (int i = 0; i <= image_.width(); ++i) {
           painter.drawLine(zoom_*i, 0, zoom_*i, zoom_*image_.height());
        }
        for (int j = 0; j<= image_.height(); ++j) {
           painter.drawLine(0, zoom_*j, zoom_*image_.width(), zoom_*j);
        }
    }
    for (int i = 0; i < image_.width(); ++i) {
        for (int j = 0; j < image_.height(); ++j) {
           QRect rect = pixelRect(i, j);
           if (e->region().intersects(rect)){
                QColor color = QColor::fromRgb(image_.pixel(i, j));
                if (color.alpha() < 255)
                    painter.fillRect(rect, Qt::white);
                painter.fillRect(rect, color);
           }
        }
    }
}
