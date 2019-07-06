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


#include "errorinfo.h"

ErrorInfo::ErrorInfo() :
    m_category(QString("unknown")), m_operation("unknown operation"),
    m_message(QString("Unknown error")),
    m_reason(QString("Improperly constructed ErrorInfo"))
{

}

ErrorInfo::ErrorInfo(QString category, QString operation,
                     QString message, QString reason) :
    m_category(category), m_operation(operation),
    m_message(message),m_reason(reason)
{

}

QString ErrorInfo::category() const
{
    return m_category;
}

void ErrorInfo::setCategory(const QString &category)
{
    m_category = category;
}

QString ErrorInfo::operation() const
{
    return m_operation;
}

void ErrorInfo::setOperation(const QString &operation)
{
    m_operation = operation;
}

QString ErrorInfo::message() const
{
    return m_message;
}

void ErrorInfo::setMessage(const QString &message)
{
    m_message = message;
}

QString ErrorInfo::reason() const
{
    return m_reason;
}

void ErrorInfo::setReason(const QString &reason)
{
    m_reason = reason;
}

void ErrorInfo::raise() const
{
    throw *this;
}

ErrorInfo *ErrorInfo::clone() const
{
    return new ErrorInfo(*this);
}
