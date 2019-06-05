#ifndef XMLSERIALIZER_H
#define XMLSERIALIZER_H

#include <QtCore>
#include "asyncworker.h"

/*!
 * \brief The abstract base class for xml serializers
 * \author arturianec100
 */
class XmlSerializer : public AsyncWorker
{
    Q_OBJECT
public:
    explicit XmlSerializer(QObject *parent = nullptr);
    virtual ~XmlSerializer() override = default;

signals:
    void serialized(QXmlStreamWriter *pWriter, QVariant data);
    void deserialized(QXmlStreamReader *pReader, QVariant data);

    void serializationError(QString errorMessage, QXmlStreamWriter *pWriter);
    void deserializationError(QString errorMessage, QXmlStreamReader *pReader);

public slots:
    virtual void serialize(QXmlStreamWriter *pWriter, QVariant data) = 0;
    virtual void deserialize(QXmlStreamReader *pReader, QVariant data) = 0;
};

#endif // XMLSERIALIZER_H
