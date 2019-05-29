#include "diagramstorage.h"

DiagramStorage::DiagramStorage(QObject *parent) : QObject(parent)
{

}

DiagramStorage::~DiagramStorage()
{
    closeAll();
}

void DiagramStorage::closeAll()
{
    while (!m_diagrams.empty()) {
        auto pDiagramInfo = m_diagrams.last();
        close(pDiagramInfo->m_pFile->fileName());
    }
}
