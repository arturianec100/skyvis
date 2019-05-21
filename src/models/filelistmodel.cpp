#include "filelistmodel.h"

FileListModel::FileListModel(DiagramStorage *storage, QObject *parent) :
    QAbstractListModel(parent), m_pStorage(storage)
{

}
