#ifndef HEXSPINBOX_H
#define HEXSPINBOX_H

#include <QSpinBox>

class HexSpinBox : public QSpinBox
{
public:
    HexSpinBox();
    HexSpinBox(QWidget *);
    ~HexSpinBox();

protected:
    QValidator::State validate(QString &, int &) const;
    int valueFromText(const QString &) const;
    QString textFromValue(int) const;

private:
    QRegularExpressionValidator *validator_;

};

#endif // HEXSPINBOX_H
