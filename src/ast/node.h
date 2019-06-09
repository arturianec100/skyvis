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


#ifndef NODE_H
#define NODE_H

#include <QtCore>
#include "connection.h"

/*!
 * \brief AST Node of the diagram.
 * \author arturianec100
 *
 * Connections are **lists of pairs** instead of **map** because order of connections is important.
 */
class Node : public QObject
{
    Q_OBJECT
public:
    using ConnectionPair = QPair<QString, Connection *>;
    using ConnectionList = QLinkedList<ConnectionPair>;

    explicit Node(QObject *parent = nullptr);
    virtual ~Node() override = default;

    QMap<QString, QString> &metaData();

    ConnectionList &input();

    ConnectionList &output();

    Connection *removeConnection(QString &connectionName);
    Connection *removeConnection(Connection *connection);
    void disconnectFromAST();

private:
    QMap<QString, QString> m_metaData;
    ConnectionList m_input;
    ConnectionList m_output;
};

Connection *connectNodes(Node *fromNode, Node *toNode,
                  QString &fromOutput, QString &toInput,
                  QString &typeName);

#endif // NODE_H
