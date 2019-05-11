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


#include "asyncworker.h"

AsyncWorker::AsyncWorker(QObject *parent, QThread::Priority priority) :
    QObject(nullptr), m_pThread(new QThread(parent))
{
    moveToThread(m_pThread);
    m_pThread->start(priority);
}

QThread *AsyncWorker::thread() const
{
    return m_pThread;
}
/*
void AsyncWorker::onAppQuit()
{
    auto pMainThread = QCoreApplication::instance()->thread();
    // I think memory leak during app closing is acceptable
    m_pThread->setParent(nullptr);
    if (m_pThread->isRunning() || !m_pThread->isFinished()) {
        m_pThread->quit();
        while (m_pThread->isRunning() || !m_pThread->isFinished()) {
            pMainThread->msleep(100);
        }
    }
}*/
