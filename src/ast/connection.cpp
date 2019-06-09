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


#include "connection.h"

Connection::Connection(QObject *parent, Node *from, Node *to) : QObject(parent),
    m_pFromNode(from), m_pToNode(to)
{

}

Node *Connection::fromNode() const
{
    return m_pFromNode;
}

void Connection::setFromNode(Node *value)
{
    m_pFromNode = value;
    emit fromNodeChanged(value);
}

Node *Connection::toNode() const
{
    return m_pToNode;
}

void Connection::setToNode(Node *value)
{
    m_pToNode = value;
    emit toNodeChanged(value);
}

QString Connection::typeName() const
{
    return m_typeName;
}

void Connection::setTypeName(const QString &typeName)
{
    m_typeName = typeName;
    emit typeNameChanged(typeName);
}
