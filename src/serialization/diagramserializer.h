#ifndef DIAGRAMSERIALIZER_H
#define DIAGRAMSERIALIZER_H

#include <QtCore>
#include "../abstract/textserializer.h"

class DiagramSerializer : public TextSerializer
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

private:
    // TODO: use xml serializers
};

#endif // DIAGRAMSERIALIZER_H
