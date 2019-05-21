#ifndef DIAGRAMSERIALIZER_H
#define DIAGRAMSERIALIZER_H

#include <QtCore>
#include "../storage/diagraminfo.h"

class DiagramSerializer : public QObject
{
    Q_OBJECT
public:
    explicit DiagramSerializer(QObject *parent = nullptr);
    virtual ~DiagramSerializer() override = default;

signals:
    void serialized(QString filePath);
    void deserialized(QString filePath, DiagramInfo *diagram);

    void serializationError(QString errorString);
    void deserializationError(QString errorString);

public slots:
    // TODO: implement
    void serialize(QString filePath, DiagramInfo *diagram);
    void deserialize(QString filePath);
};

#endif // DIAGRAMSERIALIZER_H
