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


#ifndef XMLSERIALIZER_H
#define XMLSERIALIZER_H

#include <QtCore>
#include "../asyncworker.h"

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

public slots:
    virtual void serialize(QXmlStreamWriter *pWriter, QVariant data) = 0;
    virtual void deserialize(QXmlStreamReader *pReader, QVariant data) = 0;
};

#endif // XMLSERIALIZER_H
