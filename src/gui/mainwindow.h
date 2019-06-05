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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtWidgets>
#include "../project/project.h"
#include "diagramspace.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(Project* project READ project)
public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override;

    Project *project() const;

    virtual void closeEvent(QCloseEvent *event) override;

signals:
    void userSelectedDirOfProjectToOpen(QString dir);

public slots:
    void quitApplication();

    void openDiagram(QString filePath);

    void openProjectDialog();
    void aboutMessageBox();
    void updateProjectTree();

    void onProjectTreeItemClicked(const QModelIndex &index);

protected:
    void stopWorkerThreads();

    void setupMenubar() const;
    void setupToolbar() const;
    void setupProjectTree() const;
    void setupObjectsHierarchy() const;

private:
    Ui::MainWindow *ui;
    QFileSystemModel *m_pFSModel;
    Project *m_pProject;
    DiagramSpace *m_pSpace;
};

#endif // MAINWINDOW_H
