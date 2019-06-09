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


#ifndef DIAGRAMINFO_H
#define DIAGRAMINFO_H

#include <QtCore>
#include <QtWidgets>
#include "../ast/diagram.h"

/*!
 * \brief The _low level_ struct that contain data required for DiagramStorage
 * \author arturianec100
 */
struct DiagramInfo {
    QString m_filePath;
    QGraphicsScene *m_pScene;
    Diagram *m_pAst;

    DiagramInfo(QString filePath = QString(), QGraphicsScene *pScene = nullptr,
                Diagram *pAst = nullptr);
    DiagramInfo(const DiagramInfo &other) = default;
    ~DiagramInfo();

    QString name() const;
};

Q_DECLARE_METATYPE(DiagramInfo);
Q_DECLARE_METATYPE(DiagramInfo*);

#endif // DIAGRAMINFO_H
