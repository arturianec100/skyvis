#ifndef DIAGRAMSTORAGE_H
#define DIAGRAMSTORAGE_H

#include <QtCore>
#include "diagraminfo.h"

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
    void closed(QString fileName);

public slots:
    // TODO: implement
    void open(QString filePath);
    void close(QString fileName);

protected:
    void closeAll();

private:
    QVector<DiagramInfo *> m_diagrams;
};

#endif // DIAGRAMSTORAGE_H
