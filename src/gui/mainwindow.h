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
/*!
 * \class MainWindow
 * \brief The MainWindow class.
 * \author arturianec100
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(Project* project READ project)
public:
    //! A constructor.
    /*!
     * \brief MainWindow.
     * \param parent is a parent of this object. By default it's a nullptr.
     * \sa %QMainWindow, %QWidget, <a href=https://wiki.qt.io/Qt_for_Beginners#Parenting_system>Parenting System</a>
     */
    explicit MainWindow(QWidget *parent = nullptr);

    //! A destructor.
    /*!
     * \brief ~MainWindow
     */
    virtual ~MainWindow() override;

    //! Getter for class member (current project).
    /*!
     * \brief project
     * \return m_pProject
     * \sa %Project.
     */
    Project *project() const;

    //TODO: write docs for this function
    virtual void closeEvent(QCloseEvent *event) override;

signals:
    void userSelectedDirOfProjectToOpen(QString dir);

public slots:
    //! Quit function
    /*!
     * \brief quitApplication
     * Stops threads and initiates exit
     */
    void quitApplication();

    //! function that opens diagram in given workspace
    /*!
     * \brief openDiagram
     * \param filePath is given workspace in which the work will be performed
     */
    void openDiagram(QString filePath);


    void openProjectDialog();

    //! Function that will create new window with application info, like decription, version and contributors.
    void aboutMessageBox();

    void updateProjectTree();

    void onProjectTreeItemClicked(const QModelIndex &index);

protected:
    void stopWorkerThreads();

    //All setup function bellow will call on startup

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
