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
#include "../storage/diagraminfo.h"
#include "../storage/diagramstorage.h"

/*!
 * \brief The fasade for all diagram related stuff
 * \author arturianec100
 */
class DiagramSpace : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QTabWidget tabs READ tabs)
public:
    using TabViewPair = QPair<QTab *, QGraphicsView *>;

    explicit DiagramSpace(QObject *parent, QTabWidget *pTabs);
    virtual ~DiagramSpace() override = default;

    QTabWidget *tabs() const;

signals:
    // TODO: connect with storage
    void diagramOpeningRequested(QString fileName);
    void diagramClosingRequested(QString fileName);

public slots:
    void openDiagram(QString fileName);
    void closeDiagram(int index);

    void showOpenedDiagram(DiagramInfo *pDiagram);

private:
    QTabWidget *m_pTabs;
    DiagramStorage *m_pStorage;
    QMap<int, DiagramInfo *> m_diagramIndexes;
};

#endif // DIAGRAMSPACE_H
