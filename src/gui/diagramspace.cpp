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


#include "diagramspace.h"

DiagramSpace::DiagramSpace(QObject *parent) :
    CustomQObject(parent),
    m_pStorage(new DiagramStorage(this)),
    m_pCurrentDiagram(nullptr), m_pCurrentDiagramForSaving(nullptr)
{
    // Crutch: get "GraphicsView singleton" from parent (assumed it's MainWindow) until "multi diagram" will be solved
    m_pView = parent->findChild<QGraphicsView *>();

    connect(this, &DiagramSpace::diagramOpeningRequested,
            m_pStorage, &DiagramStorage::open);
    connect(this, &DiagramSpace::diagramClosingRequested,
            m_pStorage, &DiagramStorage::close);
    connect(this, &DiagramSpace::diagramSavingRequested,
            m_pStorage, qOverload<DiagramInfo *>(&DiagramStorage::save));
    connect(m_pStorage, &DiagramStorage::opened,
            this, &DiagramSpace::onOpened);
    connect(m_pStorage, &DiagramStorage::closed,
            this, &DiagramSpace::onClosed);
    connect(m_pStorage, &DiagramStorage::saved,
            this, &DiagramSpace::onSaved);
    connect(m_pStorage, &DiagramStorage::savedAndClosedAll,
            this, &DiagramSpace::onSavedAndClosedAll);
}

void DiagramSpace::openDiagram(QString fileName)
{
    emit diagramOpeningRequested(fileName);
}

void DiagramSpace::closeDiagram(int index)
{
    if (true) {
        emit diagramClosingRequested(m_pCurrentDiagram);
    } else {
        emit errorOccurred(ErrorInfo("storage",
                                     tr("closing diagram"),
                                     tr("Can't close diagram at tab     %1").arg(index),
                                     tr("Diagram wasn't opened")));
    }
}

void DiagramSpace::saveCurrentDiagram()
{
    if (true) {
        m_pCurrentDiagramForSaving = currentDiagram();
        emit diagramSavingRequested(m_pCurrentDiagramForSaving);
    } else {
        emit errorOccurred(ErrorInfo("serialization",
                                     tr("saving current diagram"),
                                     tr("Can't save diagram"),
                                     tr("Diagram wasn't opened")));
    }
}

void DiagramSpace::saveAndCloseAllDiagrams()
{
    emit closingAllDiagramsRequested();
}

void DiagramSpace::onOpened(DiagramInfo *pDiagram)
{
    m_pView->setScene(pDiagram->m_pScene);
    // TODO: set also diagram controller
}

void DiagramSpace::onClosed(DiagramInfo *pDiagram)
{
    m_pView->setScene(nullptr);
    // TODO: unset also diagram controller
}

void DiagramSpace::onSaved(DiagramInfo *pDiagram)
{

}

void DiagramSpace::onSavedAndClosedAll()
{

}

void DiagramSpace::onDiagramStorageError(ErrorInfo error)
{
    emit errorOccurred(error);
}

DiagramInfo *DiagramSpace::currentDiagram() const
{
    return m_pCurrentDiagram;
}

void DiagramSpace::updateCurrentDiagram(int index)
{

}
