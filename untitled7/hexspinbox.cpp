#include "hexspinbox.h"

#include <QRegularExpression>

HexSpinBox::HexSpinBox()
{
    validator_ = new QRegularExpressionValidator(QRegularExpression(tr("[0-9A-Fa-f]{1,8}")), this);
}

HexSpinBox::HexSpinBox(QWidget *ptr) : QSpinBox(ptr)
{
    validator_ = new QRegularExpressionValidator(QRegularExpression(tr("[0-9A-Fa-f]{1,8}")), this);
}

HexSpinBox::~HexSpinBox()
{}

QValidator::State HexSpinBox::validate(QString &text, int &n) const
{
   return validator_->validate(text, n);
}

int HexSpinBox::valueFromText(const QString &text) const
{
    bool ok;
    return text.toInt(&ok, 16);
}

QString HexSpinBox::textFromValue(int n) const
{
    return QString::number(n, 16).toUpper();
}
