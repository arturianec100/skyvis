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


#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore>
#include "../abstract/asyncworker.h"

class Project : public AsyncWorker
{
    Q_OBJECT
    Q_PROPERTY(QDir dir READ dir)
    Q_PROPERTY(bool opened READ isOpened)
public:
    explicit Project(QObject *parent = nullptr);

    QDir dir() const;
    bool isOpened() const;

signals:
    void opened(QDir dir);
    void closed(QDir dir);

    void startedOpening(QDir dir);
    void startedClosing(QDir dir);

    void errorOpening(QDir dir);
    void errorClosing(QDir dir);

public slots:
    void open(QDir dir);
    void close();

private:
    QDir m_dir;
    bool m_opened;
};

#endif // PROJECT_H
