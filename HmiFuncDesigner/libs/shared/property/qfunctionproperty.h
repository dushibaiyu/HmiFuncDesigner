#ifndef QFUNCTIONPROPERTY_H
#define QFUNCTIONPROPERTY_H

#include "qabstractproperty.h"
#include <QLabel>

class QFunctionProperty : public QAbstractProperty
{
    Q_OBJECT
public:
    Q_INVOKABLE QFunctionProperty(QAbstractProperty* parent = NULL);
    QIcon getValueIcon();
    QString getValueText();
};

#endif
