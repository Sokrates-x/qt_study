#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QColor>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setPenColor(const QColor &c) { pen_color_ = c; }
    QColor penColor() const { return pen_color_; }

    void setZoomFactor(int i) {
        if (i < 1)
            i = 1;
        if (i != zoom_) {
            zoom_ = i;
            update();
            updateGeometry();
        }
    }

    int zoomFactor() const { return zoom_; }

    void setIconImage(const QImage &img) {
        if (img != image_)
        {
           image_ = img.convertToFormat(QImage::Format_ARGB32);
           update();
           updateGeometry();
        }
    }
    QImage iconImage() const { return image_; }

    QSize sizeHint() const;

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

private:

    void setImagePixel(const QPoint &, bool);
    QRect pixelRect(int, int);

    QColor pen_color_;
    int zoom_;
    QImage image_;
};
#endif // WIDGET_H
