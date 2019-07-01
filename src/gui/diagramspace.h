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


#ifndef DIAGRAMSPACE_H
#define DIAGRAMSPACE_H

#include <QtCore>
#include <QtWidgets>
#include "../customqobject.h"
#include "../storage/diagraminfo.h"
#include "../storage/diagramstorage.h"

/*!
 * \brief The fasade for all diagram related stuff
 * \author arturianec100
 */
class DiagramSpace : public CustomQObject
{
    Q_OBJECT
    Q_PROPERTY(DiagramInfo* currentDiagram READ currentDiagram)
public:
    explicit DiagramSpace(QObject *parent);
    virtual ~DiagramSpace() override = default;

    DiagramInfo *currentDiagram() const;

signals:
    void diagramOpeningRequested(QString fileName);
    void diagramClosingRequested(DiagramInfo *pDiagram);
    void diagramSavingRequested(DiagramInfo *pDiagram);
    void closingAllDiagramsRequested();

    void currentDiagramSaved();
    void allDiagramsSavedAndClosed();

public slots:
    void openDiagram(QString fileName);
    void closeDiagram(int index);
    void saveCurrentDiagram();
    void saveAndCloseAllDiagrams();

protected slots:
    // TODO: implement
    void onOpened(DiagramInfo *pDiagram);
    void onClosed(DiagramInfo *pDiagram);
    void onSaved(DiagramInfo *pDiagram);
    void onSavedAndClosedAll();

    void onDiagramStorageError(ErrorInfo error);

protected:
    void updateCurrentDiagram(int index);

private:
    DiagramStorage *m_pStorage;
    DiagramInfo *m_pCurrentDiagram;
    DiagramInfo *m_pCurrentDiagramForSaving;
    // Temporarily store "GraphicsView singleton" until "multi diagram" will be solved
    QGraphicsView *m_pView;
};

#endif // DIAGRAMSPACE_H
