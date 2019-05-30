#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QtCore>
#include "../abstract/asyncworker.h"
#include "../storage/diagraminfo.h"

/*!
 * \brief The abstract base class for all serializers
 * \author arturianec100
 */
class Serializer : public AsyncWorker
{
    Q_OBJECT
public:
    explicit Serializer(QObject *parent = nullptr);
    virtual ~Serializer() override = default;

signals:
    void serialized(QTextStream *pStream, QVariant data);
    void deserialized(QTextStream *pStream, QVariant data);

    void serializationError(QString errorString);
    void deserializationError(QString errorString);

public slots:
    virtual void serialize(QTextStream *pStream, QVariant data) = 0;
    virtual void deserialize(QTextStream *pStream, QVariant data) = 0;
};

#endif // SERIALIZER_H
