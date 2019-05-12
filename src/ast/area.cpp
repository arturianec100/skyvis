#include "area.h"

Area::Area(QObject *parent) : QObject(parent)
{

}

QString Area::name() const
{
    return m_name;
}

void Area::setName(const QString &name)
{
    m_name = name;
}

QLinkedList<Node *> &Area::nodes()
{
    return m_nodes;
}
