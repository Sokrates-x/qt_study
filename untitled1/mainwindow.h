#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
//#include <QHBoxLayout>
//#include <QSlider>
//#include <QSpinBox>

class QSlider;
class QSpinBox;

class MainWindow : QWidget
{
    Q_OBJECT

public:

    MainWindow();
   ~MainWindow();



private:

    QSlider *slider_;
    QSpinBox *sbox_;

};


#endif // MAINWINDOW_H
