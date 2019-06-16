#ifndef ASTELEMENT_H
#define ASTELEMENT_H

#include <QtCore>
#include "../customqobject.h"

class AstElement : public CustomQObject
{
    Q_OBJECT
public:
    explicit AstElement(QObject *parent = nullptr);
    virtual ~AstElement() override = default;
};

#endif // ASTELEMENT_H
