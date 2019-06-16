#ifndef CUSTOMQOBJECT_H
#define CUSTOMQOBJECT_H

#include <QObject>
#include "errorinfo.h"

class CustomQObject : public QObject
{
    Q_OBJECT
public:
    explicit CustomQObject(QObject *parent = nullptr);
    virtual ~CustomQObject() override = default;

signals:
    virtual void errorOccurred(ErrorInfo error);
};

#endif // CUSTOMQOBJECT_H
