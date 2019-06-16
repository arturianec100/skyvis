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


#include "node.h"
#include "../common.h"

Node::Node(QObject *parent) : AstElement(parent)
{

}

QMap<QString, QString> &Node::metaData()
{
    return m_metaData;
}

Node::ConnectionList &Node::input()
{
    return m_input;
}

Node::ConnectionList &Node::output()
{
    return m_output;
}

Connection *Node::removeConnection(QString &connectionName)
{
    for (auto itPair = m_output.begin(); itPair != m_output.end(); ++itPair) {
        if (itPair->first == connectionName) {
            auto pConn = itPair->second;
            m_output.erase(itPair);
            return pConn;
        }
    }
    for (auto itPair = m_input.begin(); itPair != m_input.end(); ++itPair) {
        if (itPair->first == connectionName) {
            auto pConn = itPair->second;
            m_input.erase(itPair);
            return pConn;
        }
    }
    return nullptr;
}

Connection *Node::removeConnection(Connection *connection)
{
    //! This version of iteration is used because **erase** requires an **iterator**
    for (auto itPair = m_output.begin(); itPair != m_output.end(); ++itPair) {
        if (itPair->second == connection) {
            m_output.erase(itPair);
            return connection;
        }
    }
    for (auto itPair = m_input.begin(); itPair != m_input.end(); ++itPair) {
        if (itPair->second == connection) {
            m_output.erase(itPair);
            return connection;
        }
    }
    return nullptr;
}

void Node::disconnectFromAST()
{
    for (auto pair : m_input) {
        Connection *pConn = removeConnection(pair.second);
        if (pConn->fromNode() != nullptr) {
            pConn->fromNode()->removeConnection(pConn);
        }
        SAFE_DELETE(pConn)
    }
    for (auto pair : m_output) {
        Connection *pConn = removeConnection(pair.second);
        if (pConn->toNode() != nullptr) {
            pConn->toNode()->removeConnection(pConn);
        }
        SAFE_DELETE(pConn)
    }
}

Connection *connectNodes(Node *fromNode, Node *toNode,
                   QString &fromOutput, QString &toInput, QString &typeName)
{
    Connection *pConn = new Connection(fromNode, fromNode, toNode);
    pConn->setTypeName(typeName);
    fromNode->output().append(qMakePair(fromOutput, pConn));
    toNode->input().append(qMakePair(toInput, pConn));
    return pConn;
}
