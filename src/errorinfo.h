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


#ifndef ERRORINFO_H
#define ERRORINFO_H

#include <QtCore>

class ErrorInfo : public QException
{
public:    
    ErrorInfo();
    ErrorInfo(QString m_category, QString m_message, QString m_reason);
    ErrorInfo(ErrorInfo const& other) = default;
    virtual ~ErrorInfo() override = default;

    ErrorInfo & operator = (const ErrorInfo &other) = default;

private:
    QString m_category;
    QString m_message;
    QString m_reason;
};

Q_DECLARE_METATYPE(ErrorInfo)

#endif // ERRORINFO_H
