#include "diagram.h"

Diagram::Diagram(QObject *parent) : QObject(parent)
{

}

QLinkedList<Node *> &Diagram::nodes()
{
    return m_nodes;
}

QLinkedList<Area *> &Diagram::areas()
{
    return m_areas;
}
