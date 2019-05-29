#ifndef DIAGRAMSERIALIZER_H
#define DIAGRAMSERIALIZER_H

#include <QtCore>
#include "../abstract/asyncworker.h"
#include "../storage/diagraminfo.h"

/*!
 * \brief Diagram serialization. The fasade for _low-level_ serializators
 * \author arturianec100
 */
class DiagramSerializer : public AsyncWorker
{
    Q_OBJECT
public:
    explicit DiagramSerializer(QObject *parent = nullptr);
    virtual ~DiagramSerializer() override = default;

signals:
    void serialized(QTextStream *pStream, DiagramInfo *pDiagram);
    void deserialized(QTextStream *pStream, DiagramInfo *pDiagram);

    void serializationError(QString errorString);
    void deserializationError(QString errorString);

public slots:
    // TODO: implement
    void serialize(QTextStream *pStream, DiagramInfo *pDiagram);
    void deserialize(QTextStream *pStream, DiagramInfo *pDiagram);
};

#endif // DIAGRAMSERIALIZER_H
