/**
 ** This file is part of the skyvis project.
 ** Copyright 2019 arturianec100 <arturianec100@gmail.com>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/


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
    void errorOccurred(ErrorInfo error);
};

#endif // CUSTOMQOBJECT_H
