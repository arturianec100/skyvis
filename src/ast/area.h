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


#ifndef AREA_H
#define AREA_H

#include <QtCore>
#include "node.h"

/*!
 * \brief AST Area that describes nodes.
 * \author arturianec100
 *
 * It's VP equivalent of TP comments. AST version must know only attached nodes. Rect and other visualization stuff must be handled by **gui**.
 */
class Area : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
public:
    using NodeList = QLinkedList<Node *>;

    explicit Area(QObject *parent = nullptr);
    virtual ~Area() override = default;

    QString name() const;
    void setName(const QString &name);

    QLinkedList<Node *> &nodes();

private:
    QString m_name;
    QLinkedList<Node *> m_nodes;
};

#endif // AREA_H
