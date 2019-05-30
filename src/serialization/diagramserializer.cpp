#include "diagramserializer.h"

DiagramSerializer::DiagramSerializer(QObject *parent) : Serializer(parent)
{

}

void DiagramSerializer::serialize(QTextStream *pStream, QVariant data)
{
    if (!m_serializers.isEmpty()) {
        emit serializationRequested(pStream, data);
    } else {
        emit serializationError(tr("Can't serialize a diagram because DiagramSerializer wasn't properly constructed"));
    }
}

void DiagramSerializer::deserialize(QTextStream *pStream, QVariant data)
{
    if (!m_serializers.isEmpty()) {
        emit deserializationRequested(pStream, data);
    } else {
        emit deserializationError(tr("Can't deserialize a diagram because DiagramSerializer wasn't properly constructed"));
    }
}

void DiagramSerializer::addSerializer(Serializer *pSerializer)
{
    pSerializer->setParent(this);
    // TODO connect and disconnect s/s on serializers
    m_serializers.append(pSerializer);
}
