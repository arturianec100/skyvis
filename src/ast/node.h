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
