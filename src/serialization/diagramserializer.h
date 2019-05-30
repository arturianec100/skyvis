#ifndef DIAGRAMSERIALIZER_H
#define DIAGRAMSERIALIZER_H

#include <QtCore>
#include "../abstract/serializer.h"

class DiagramSerializer : public Serializer
{
    Q_OBJECT
public:
    explicit DiagramSerializer(QObject *parent = nullptr);
    virtual ~DiagramSerializer() override = default;

signals:
    void serializationRequested(QTextStream *pStream, QVariant data);
    void deserializationRequested(QTextStream *pStream, QVariant data);

public slots:
    virtual void serialize(QTextStream *pStream, QVariant data) override;
    virtual void deserialize(QTextStream *pStream, QVariant data) override;

protected:
    void addSerializer(Serializer *pSerializer);

private:
    QVector<Serializer *> m_serializers;
};

#endif // DIAGRAMSERIALIZER_H
