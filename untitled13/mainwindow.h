#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);

private:
    bool readFile(const QString &);
    QTextEdit *tedit_;

};
#endif // MAINWINDOW_H
