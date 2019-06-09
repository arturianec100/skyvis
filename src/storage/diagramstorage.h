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


#ifndef DIAGRAMSTORAGE_H
#define DIAGRAMSTORAGE_H

#include <QtCore>
#include "diagraminfo.h"
#include "../serialization/diagramserializer.h"

/*!
 * \brief Stores diagrams at RAM and ROM. Provides API for manual opening and closing diagrams
 * \author arturianec100
 */
class DiagramStorage : public QObject
{
    Q_OBJECT
public:
    explicit DiagramStorage(QObject *parent = nullptr);
    virtual ~DiagramStorage() override;

signals:
    void opened(QString filePath);
    void closed(DiagramInfo *pDiagram);
    void saved(QString filePath);
    void savedAndClosedAll();

    void errorOpening(QString errorMessage);
    void errorClosing(QString errorMessage);
    void errorSaving(QString errorMessage);

    void serializationRequested(QTextStream *pStream, QVariant data);
    void deserializationRequested(QTextStream *pStream, QVariant data);

public slots:
    void open(QString filePath);
    void close(DiagramInfo *pDiagram);
    void save(DiagramInfo *pDiagram);
    void save(QString filePath, DiagramInfo *pDiagram);
    void saveAndCloseAll();

    // TODO: implement
    void markAsDirty(DiagramInfo *pDiagram);
    void markAsSaved(DiagramInfo *pDiagram);

protected slots:
    void onSerialized(QTextStream *pStream, QVariant data);
    void onDeserialized(QTextStream *pStream, QVariant data);

    void onSerializationError(QString errorString);
    void onDeserializationError(QString errorString);

protected:
    void free(DiagramInfo *pDiagram);
    QString closeStreamAndGetFilePath(QFile *pFile);
    QString closeStreamAndGetFilePath(QTextStream *pStream);

private:
    QVector<DiagramInfo *> m_diagrams;
    QLinkedList<QPair<QFile *, QTextStream *>> m_activeStreams;
    QLinkedList<DiagramInfo *> m_dirtyDiagrams;
    QLinkedList<QPair<QString, DiagramInfo *>> m_aboutToCloseDiagrams;
    DiagramSerializer *m_pSerializer;
};

#endif // DIAGRAMSTORAGE_H
