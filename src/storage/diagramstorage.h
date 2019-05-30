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
    void save(QString filePath, DiagramInfo *pDiagram);
    void saveAndCloseAll();

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
