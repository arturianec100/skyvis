#include "diagramstorage.h"
#include <algorithm>

DiagramStorage::DiagramStorage(QObject *parent) : QObject(parent),
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
    connect(m_pSerializer, &DiagramSerializer::serializationError,
            this, &DiagramStorage::onSerializationError);
    connect(m_pSerializer, &DiagramSerializer::deserializationError,
            this, &DiagramStorage::onDeserializationError);
}

DiagramStorage::~DiagramStorage()
{
    saveAndCloseAll();
}

void DiagramStorage::open(QString filePath)
{
    QFile *pFile = new QFile(filePath);
    if (!pFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        emit errorOpening(tr("Can't load diagram from file %1").arg(filePath));
        return;
    }
    QTextStream *pStream = new QTextStream(pFile);
    m_activeStreams.append(qMakePair(pFile, pStream));
    DiagramInfo *pDiagram = new DiagramInfo(filePath);
    emit deserializationRequested(pStream, pDiagram);
}

void DiagramStorage::close(DiagramInfo *pDiagram)
{
    if ((pDiagram == nullptr) || (!m_diagrams.contains(pDiagram))) {
        emit errorClosing(tr("Can't close diagram because it wasn't open"));
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

void DiagramStorage::save(QString filePath, DiagramInfo *pDiagram)
{
    if ((pDiagram == nullptr) || (!m_diagrams.contains(pDiagram))) {
        emit errorSaving(tr("Can't save diagram because it wasn't open: %1")
                          .arg(filePath));
        return;
    }
    QFile *pFile = new QFile(filePath);
    if (!pFile->open(QIODevice::WriteOnly | QIODevice::Text)) {
        emit errorOpening(tr("Can't save diagram to file %1").arg(filePath));
        return;
    }
    QTextStream *pStream = new QTextStream(pFile);
    m_activeStreams.append(qMakePair(pFile, pStream));
    emit deserializationRequested(pStream, pDiagram);
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

void DiagramStorage::onSerialized(QTextStream *pStream, DiagramInfo *pDiagram)
{
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

void DiagramStorage::onDeserialized(QTextStream *pStream, DiagramInfo *pDiagram)
{
    m_diagrams.append(pDiagram);
    QString filePath = closeStreamAndGetFilePath(pStream);
    emit opened(filePath);
}

void DiagramStorage::onSerializationError(QString errorString)
{
    emit errorSaving(tr("Can't save diagram because of fail at serialization stage: %1").arg(errorString));
}

void DiagramStorage::onDeserializationError(QString errorString)
{
    emit errorOpening(tr("Can't open diagram because of fail at serialization stage: %1").arg(errorString));
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
