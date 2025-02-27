#ifndef QFRAMEHOST_H
#define QFRAMEHOST_H

#include "qwidgethost.h"

class QFrameHost : public QWidgetHost
{
    Q_OBJECT
public:
    Q_INVOKABLE QFrameHost(QAbstractHost *parent = 0);

    static QString getShowName();
    static QString getShowIcon();
    static QString getShowGroup();

public slots:
    void setFrameShape(int frameShape);
    int frameShape();

    void setFrameShadow(int frameShadow);
    int frameShadow();

protected:
    void initProperty() override;

protected:
    void createObject() override;
    // 控件支持的功能事件
    QStringList supportFuncEvents() override;
};

#endif // QFRAMEHOST_H
