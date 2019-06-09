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


#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtCore>

class Node;

/*!
 * \brief AST Connection between nodes.
 * \author arturianec100
 *
 * Currently names of input and outout pins are handled by nodes. Thoughts about another structure are welcome, but **discuss before coding**.
 */
class Connection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Node* fromNode READ fromNode WRITE setFromNode NOTIFY fromNodeChanged)
    Q_PROPERTY(Node* toNode READ toNode WRITE setToNode NOTIFY toNodeChanged)
    Q_PROPERTY(QString typeName READ typeName WRITE setTypeName NOTIFY typeNameChanged)
public:
    explicit Connection(QObject *parent = nullptr,
                        Node *from = nullptr, Node *to = nullptr);
    virtual ~Connection() override = default;

    Node *fromNode() const;
    void setFromNode(Node *value);

    Node *toNode() const;
    void setToNode(Node *value);

    QString typeName() const;
    void setTypeName(const QString &typeName);

signals:
    void fromNodeChanged(Node *newFromNode);
    void toNodeChanged(Node *newToNode);
    void typeNameChanged(const QString &newTypeName);

public slots:

private:
    Node *m_pFromNode;
    Node *m_pToNode;
    QString m_typeName;
};

#endif // CONNECTION_H
