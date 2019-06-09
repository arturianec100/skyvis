/**
 ** This file is part of the skyvis project.
 ** Copyright 2019 arturianec100 <arturianec100@gmail.com>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/


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
