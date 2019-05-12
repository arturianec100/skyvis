#ifndef AREA_H
#define AREA_H

#include <QtCore>
#include "node.h"

class Area : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QLinkedList<Node *>& nodes READ nodes)
public:
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