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


/*!
* \class Error Info
* \brief The ErrorInfo class
*
* \author arturianec100
*/
class ErrorInfo : public QException
{
public:
   //! Empty constructor
   /*!
    * \brief ErrorInfo
    * Member of class will initilize by default value
    */
   ErrorInfo();

   //! A constructor with bunch of arguments
   /*!
    * \brief A Constructor
    * \param category Category or "layer" where error occurredr
    * \param operation Operation where error occurred
    * \param message Error Message
    * \param reason Error reson
    */
   ErrorInfo(QString category, QString operation,
             QString message, QString reason);
   ErrorInfo(ErrorInfo const& other) = default;
   virtual ~ErrorInfo() override = default;

   ErrorInfo & operator = (const ErrorInfo &other) = default;
   /*!
    * \brief Category or "layer" where error occurred
    */
   QString category() const;
   void setCategory(const QString &category);
   /*!
    * \brief Operation where error occurred
    */
   QString operation() const;
   void setOperation(const QString &operation);
   /*!
    * \brief Error message
    */
   QString message() const;
   void setMessage(const QString &message);
   /*!
    * \brief Error reason
    */
   QString reason() const;
   void setReason(const QString &reason);

   //! Will throw this error
   void raise() const override;

   //! Cloning current object
   /*!
    * \brief clone
    * \return Pointer to object
    */
   ErrorInfo *clone() const override;

private:
   QString m_category;
   QString m_operation;
   QString m_message;
   QString m_reason;
};

Q_DECLARE_METATYPE(ErrorInfo)

#endif // ERRORINFO_H
