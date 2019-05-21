#ifndef FILELISTMODEL_H
#define FILELISTMODEL_H

#include <QtCore>
#include "../storage/diagramstorage.h"

class FileListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit FileListModel(DiagramStorage *storage, QObject *parent = nullptr);
    virtual ~FileListModel() override = default;
    // TODO: implement model interface

signals:

public slots:

private:
    DiagramStorage *m_pStorage;
};

#endif // FILELISTMODEL_H
