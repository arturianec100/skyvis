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
