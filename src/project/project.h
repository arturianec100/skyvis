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


#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore>
#include "../asyncworker.h"

/*!
* \class Project
* \brief The Project as collection of diagrams and related data
* \author arturianec100
* \sa %AsyncWorker
*/
class Project : public AsyncWorker
{
   Q_OBJECT
   Q_PROPERTY(QString dir READ dir)
   Q_PROPERTY(bool opened READ isOpened)
public:
   //! A constructor.
   /*!
    * \brief Project
    * \param parent is a parent of this object. By default it's a nullptr.
    *  \sa %AsyncWorker <a href=https://wiki.qt.io/Qt_for_Beginners#Parenting_system>Parenting System</a>
    */
   explicit Project(QObject *parent = nullptr);

   //! Function that return directory of project.
   QString dir() const;

   //! Checks is file open
   bool isOpened() const;

signals:
   void opened(QString dir);
   void closed(QString dir);

   void startedOpening(QString dir);
   void startedClosing(QString dir);

   void errorOpening(QString dir);
   void errorClosing(QString dir);

public slots:
   //! Open directory that was got from argument
   /*!
    * \brief open
    * \param dir is a directory which will be open
    */
   void open(QString dir);

   //!Close directory that was opened ith open(QString dir) function
   void close();

private:
   QString m_dir;
   bool m_opened;
};

#endif // PROJECT_H
