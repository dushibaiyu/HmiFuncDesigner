#ifndef QIMAGEHOST_H
#define QIMAGEHOST_H

#include "qframehost.h"

class QImageHost : public QFrameHost
{
    Q_OBJECT
public:
    Q_INVOKABLE QImageHost(QAbstractHost *parent = 0);

    static QString getShowName();
    static QString getShowIcon();
    static QString getShowGroup();

protected:
    void initProperty();

protected:
    void createObject();

};

#endif // QIMAGEHOST_H
