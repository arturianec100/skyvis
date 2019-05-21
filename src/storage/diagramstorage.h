#ifndef DIAGRAMSTORAGE_H
#define DIAGRAMSTORAGE_H

#include <QtCore>
#include "diagraminfo.h"

class DiagramStorage : public QObject
{
    Q_OBJECT
public:
    explicit DiagramStorage(QObject *parent = nullptr);
    virtual ~DiagramStorage() override = default;

signals:
    void opened(QString filePath);
    void closed(QString fileName);

public slots:
    // TODO: implement
    void open(QString filePath);
    void close(QString fileName);

private:
    QVector<DiagramInfo> m_diagrams;
};

#endif // DIAGRAMSTORAGE_H
