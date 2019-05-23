#include "node.h"
#include "../common.h"

Node::Node(QObject *parent) : QObject(parent)
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
