#include "diagramspace.h"

DiagramSpace::DiagramSpace(QObject *parent, QTabWidget *pTabs) : QObject(parent),
    m_pTabs(pTabs), m_pStorage(new DiagramStorage(this))
{
    m_pTabs->removeTab(1);
    m_pTabs->removeTab(0);

    connect(this, &DiagramSpace::diagramOpeningRequested,
            m_pStorage, &DiagramStorage::open);
}

QTabWidget *DiagramSpace::tabs() const
{
    return m_pTabs;
}

void DiagramSpace::openDiagram(QString fileName)
{
    emit diagramOpeningRequested(fileName);
}

void DiagramSpace::showOpenedDiagram(DiagramInfo *pDiagram)
{
    QGraphicsView *pView = new QGraphicsView;
    pView->setScene(pDiagram->m_pScene);
    m_pTabs->addTab(pView, pDiagram->name());
    int index = m_pTabs->indexOf(pView);
    m_pTabs->setCurrentIndex(index);

    m_diagramIndexes.insert(index, pDiagram);
}
