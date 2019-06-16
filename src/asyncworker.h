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


#ifndef ASYNCWORKER_H
#define ASYNCWORKER_H

#include <QtCore>
#include "customqobject.h"

/*!
 * \brief This class should be inherited by objects that have to work in their own threads.
 * \warning All communication with "outer world" **must** be done through signals/slots. All data should be passed as parameters. Violating of "data via arguments rule" will lead to data corruption by multiple threads. All instances must be indirect children of **MainWindow** because it destroys all worker threads before quitting the app. Violating of "child of main window rule" will lead to segfault on closing of the application.
 * \author arturianec100
 *
 * **moveToThread** makes it children of the thread. So instead of parent-child there will be parent-thread-child.
 */
class AsyncWorker : public CustomQObject
{
    Q_OBJECT
    Q_PROPERTY(QThread* thread READ thread)
public:
    explicit AsyncWorker(QObject *parent = nullptr,
                         QThread::Priority priority = QThread::InheritPriority);
    virtual ~AsyncWorker() override = default;

    QThread *thread() const;

private:
    QThread *m_pThread;
};

#endif // ASYNCWORKER_H
