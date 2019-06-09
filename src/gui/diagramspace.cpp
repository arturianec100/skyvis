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

DiagramSpace::DiagramSpace(QObject *parent, QTabWidget *pTabs) : QObject(parent),
    m_pTabs(pTabs), m_pStorage(new DiagramStorage(this)),
    m_pCurrentDiagram(nullptr), m_pCurrentDiagramForSaving(nullptr)
{
    m_pTabs->removeTab(1);
    m_pTabs->removeTab(0);

    connect(this, &DiagramSpace::diagramOpeningRequested,
            m_pStorage, &DiagramStorage::open);
    connect(this, &DiagramSpace::diagramClosingRequested,
            m_pStorage, &DiagramStorage::close);
    connect(this, &DiagramSpace::diagramSavingRequested,
            m_pStorage, qOverload<DiagramInfo *>(&DiagramStorage::save));

    connect(m_pTabs, &QTabWidget::currentChanged,
            this, &DiagramSpace::updateCurrentDiagram);
    connect(m_pTabs, &QTabWidget::tabCloseRequested,
            this, &DiagramSpace::closeDiagram);
}

QTabWidget *DiagramSpace::tabs() const
{
    return m_pTabs;
}

void DiagramSpace::openDiagram(QString fileName)
{
    emit diagramOpeningRequested(fileName);
}

void DiagramSpace::closeDiagram(int index)
{
    if (auto *pDiagram = m_diagramIndexes[index]) {
        m_diagramIndexes.removeAt(index);
        emit diagramClosingRequested(pDiagram);
    } else {
        emit errorClosingDiagram(tr("Can't close diagram at tab %1 because it wasn't opened").arg(index));
    }
}

void DiagramSpace::saveCurrentDiagram()
{
    if (m_diagramIndexes.length() > 0) {
        m_pCurrentDiagramForSaving = currentDiagram();
        emit diagramSavingRequested(m_pCurrentDiagramForSaving);
    } else {
        emit errorSavingDiagram(tr("Can't save diagram because no diagram was opened"));
    }
}

void DiagramSpace::saveAndCloseAllDiagrams()
{
    emit closingAllDiagramsRequested();
}

void DiagramSpace::addTabForDiagram(DiagramInfo *pDiagram)
{
    QGraphicsView *pView = new QGraphicsView;
    pView->setScene(pDiagram->m_pScene);
    m_pTabs->addTab(pView, pDiagram->name());
    int index = m_pTabs->indexOf(pView);
    m_pTabs->setCurrentIndex(index);

    m_diagramIndexes.insert(index, pDiagram);
}

DiagramInfo *DiagramSpace::currentDiagram() const
{
    return m_pCurrentDiagram;
}

void DiagramSpace::updateCurrentDiagram(int index)
{
    m_pCurrentDiagram = m_diagramIndexes[index];
}
