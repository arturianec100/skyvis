#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QtCore>
#include "node.h"
#include "area.h"

/*!
 * \brief AST Diagram.
 * \author arturianec100
 */
class Diagram : public QObject
{
    Q_OBJECT
public:
    explicit Diagram(QObject *parent = nullptr);
    virtual ~Diagram() override = default;

    QLinkedList<Node *> &nodes();

    QLinkedList<Area *> &areas();

private:
    QLinkedList<Node *> m_nodes;
    QLinkedList<Area *> m_areas;
};

#endif // DIAGRAM_H
