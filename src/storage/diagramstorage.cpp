#include "diagramstorage.h"

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
}
