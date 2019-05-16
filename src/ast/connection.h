#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtCore>

class Node;

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
