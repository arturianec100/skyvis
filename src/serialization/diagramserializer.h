#ifndef DIAGRAMSERIALIZER_H
#define DIAGRAMSERIALIZER_H

#include <QtCore>
#include "../abstract/asyncworker.h"
#include "../storage/diagraminfo.h"

class DiagramSerializer : public AsyncWorker
{
    Q_OBJECT
public:
    explicit DiagramSerializer(QObject *parent = nullptr);
    virtual ~DiagramSerializer() override = default;

signals:
    void serialized(QTextStream *pStream);
    void deserialized(QTextStream *pStream, DiagramInfo *pDiagram);

    void serializationError(QString errorString);
    void deserializationError(QString errorString);

public slots:
    // TODO: implement
    void serialize(QTextStream *pStream, DiagramInfo *pDiagram);
    void deserialize(QTextStream *pStream);
};

#endif // DIAGRAMSERIALIZER_H
