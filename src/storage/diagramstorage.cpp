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


#include "diagramstorage.h"
#include <algorithm>

DiagramStorage::DiagramStorage(QObject *parent) : CustomQObject(parent),
    m_pSerializer(new DiagramSerializer(this))
{
    connect(this, &DiagramStorage::serializationRequested,
            m_pSerializer, &DiagramSerializer::serialize);
    connect(this, &DiagramStorage::deserializationRequested,
            m_pSerializer, &DiagramSerializer::deserialize);
    connect(m_pSerializer, &DiagramSerializer::serialized,
            this, &DiagramStorage::onSerialized);
    connect(m_pSerializer, &DiagramSerializer::deserialized,
            this, &DiagramStorage::onDeserialized);
    connect(m_pSerializer, &DiagramSerializer::errorOccurred,
            this, &DiagramStorage::onSerializationError);
}

DiagramStorage::~DiagramStorage()
{
    saveAndCloseAll();
}

void DiagramStorage::open(QString filePath)
{
    QFile *pFile = new QFile(filePath);
    if (!pFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        emit errorOccurred(ErrorInfo("serialization", tr("Can't load diagram"), tr(" Can't open file %1").arg(filePath)));
        return;
    }
    QTextStream *pStream = new QTextStream(pFile);
    m_activeStreams.append(qMakePair(pFile, pStream));
    DiagramInfo *pDiagram = new DiagramInfo(filePath);
    emit deserializationRequested(pStream, QVariant::fromValue(pDiagram));
}

void DiagramStorage::close(DiagramInfo *pDiagram)
{
    if ((pDiagram == nullptr) || (!m_diagrams.contains(pDiagram))) {
        emit errorOccurred(ErrorInfo("serialization", tr("Can't close diagram"), tr("Diagram wasn't open")));
        return;
    }
    if (m_dirtyDiagrams.contains(pDiagram)) {
        save(pDiagram->m_filePath, pDiagram);
        m_aboutToCloseDiagrams.append(qMakePair(pDiagram->m_filePath, pDiagram));
    } else {
        m_diagrams.removeAll(pDiagram);
        free(pDiagram);
        emit closed(pDiagram);
    }
}

void DiagramStorage::save(DiagramInfo *pDiagram)
{
    save(pDiagram->m_filePath, pDiagram);
}

void DiagramStorage::save(QString filePath, DiagramInfo *pDiagram)
{
    if ((pDiagram == nullptr) || (!m_diagrams.contains(pDiagram))) {
        emit errorOccurred(ErrorInfo("serialization", tr("Can't save diagram"), tr("Diagram wasn't open: %1").arg(filePath)));
        return;
    }
    QFile *pFile = new QFile(filePath);
    if (!pFile->open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOccurred(ErrorInfo("serialization", tr("Can't save diagram"), tr("Can't open file: %1").arg(filePath)));
        return;
    }
    QTextStream *pStream = new QTextStream(pFile);
    m_activeStreams.append(qMakePair(pFile, pStream));
    emit deserializationRequested(pStream, QVariant::fromValue(pDiagram));
}

void DiagramStorage::saveAndCloseAll()
{
    for (auto pDiagram : m_diagrams) {
        close(pDiagram);
    }
    while (!m_diagrams.empty()) {
        QThread::currentThread()->usleep(100);
    }
    emit savedAndClosedAll();
}

void DiagramStorage::markAsDirty(DiagramInfo *pDiagram)
{

}

void DiagramStorage::markAsSaved(DiagramInfo *pDiagram)
{

}

void DiagramStorage::onSerialized(QTextStream *pStream, QVariant data)
{
    DiagramInfo *pDiagram = data.value<DiagramInfo *>();
    m_dirtyDiagrams.removeAll(pDiagram);
    QString filePath = closeStreamAndGetFilePath(pStream);
    emit saved(filePath);
    auto itPair = std::find_if(m_aboutToCloseDiagrams.begin(),
                               m_aboutToCloseDiagrams.end(),
                               [pDiagram](QPair<QString, DiagramInfo *> &rPair) {
                                    return rPair.second == pDiagram; });
    if (itPair != m_aboutToCloseDiagrams.end()) {
        m_aboutToCloseDiagrams.erase(itPair);
        close(pDiagram);
    }
}

void DiagramStorage::onDeserialized(QTextStream *pStream, QVariant data)
{
    DiagramInfo *pDiagram = data.value<DiagramInfo *>();
    m_diagrams.append(pDiagram);
    QString filePath = closeStreamAndGetFilePath(pStream);
    emit opened(filePath);
}

void DiagramStorage::onSerializationError(ErrorInfo error)
{
    emit errorOccurred(error);
}

void DiagramStorage::free(DiagramInfo *pDiagram)
{
    m_diagrams.removeAll(pDiagram);
    delete pDiagram;
}

QString DiagramStorage::closeStreamAndGetFilePath(QFile *pFile)
{
    for (auto itPair = m_activeStreams.begin();
         itPair != m_activeStreams.end(); ++itPair) {
        if (itPair->first == pFile) {
            QString filePath = pFile->fileName();
            delete pFile;
            delete itPair->second;
            m_activeStreams.erase(itPair);
            return filePath;
        }
    }
    return QString();
}

QString DiagramStorage::closeStreamAndGetFilePath(QTextStream *pStream)
{
    for (auto itPair = m_activeStreams.begin();
         itPair != m_activeStreams.end(); ++itPair) {
        if (itPair->second == pStream) {
            QString filePath = itPair->first->fileName();
            delete pStream;
            delete itPair->first;
            m_activeStreams.erase(itPair);
            return filePath;
        }
    }
    return QString();
}
