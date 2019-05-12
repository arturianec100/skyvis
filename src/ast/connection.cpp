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
    emit fromNodeChanged();
}

Node *Connection::toNode() const
{
    return m_pToNode;
}

void Connection::setToNode(Node *value)
{
    m_pToNode = value;
    emit toNodeChanged();
}

QString Connection::typeName() const
{
    return m_typeName;
}

void Connection::setTypeName(const QString &typeName)
{
    m_typeName = typeName;
    emit typeNameChanged();
}
