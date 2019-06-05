#ifndef TEXTSERIALIZER_H
#define TEXTSERIALIZER_H

#include <QtCore>
#include "../abstract/asyncworker.h"

/*!
 * \brief The abstract base class for text serializers
 * \author arturianec100
 */
class TextSerializer : public AsyncWorker
{
    Q_OBJECT
public:
    explicit TextSerializer(QObject *parent = nullptr);
    virtual ~TextSerializer() override = default;

signals:
    void serialized(QTextStream *pStream, QVariant data);
    void deserialized(QTextStream *pStream, QVariant data);

    void serializationError(QString errorString, QTextStream *pStream);
    void deserializationError(QString errorString, QTextStream *pStream);

public slots:
    virtual void serialize(QTextStream *pStream, QVariant data) = 0;
    virtual void deserialize(QTextStream *pStream, QVariant data) = 0;
};

#endif // TEXTSERIALIZER_H
