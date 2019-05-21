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


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../appinfo.h"
#include "../common.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pFSModel(new QFileSystemModel),
    m_pProject(new Project(this))
{
    ui->setupUi(this);
    setupMenubar();
    setupToolbar();
    setupProjectTree();
    setupFileList();
    setupObjectsHierarchy();
    setupObjectInspector();

    connect(this, &MainWindow::userSelectedDirOfProjectToOpen,
            m_pProject, &Project::open);
    connect(m_pProject, &Project::opened,
            this, &MainWindow::updateProjectTree);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Project *MainWindow::project() const
{
    return m_pProject;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    stopWorkerThreads();
    event->accept();
}

void MainWindow::quitApplication()
{
    stopWorkerThreads();
    QApplication::instance()->quit();
}

void MainWindow::openDiagram(QString filePath)
{

}

void MainWindow::openProjectDialog()
{
    QString dirStr = QFileDialog::getExistingDirectory(this, tr("Select Project Directory"),
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly |
                                                    QFileDialog::DontConfirmOverwrite |
                                                    QFileDialog::ReadOnly);
    emit userSelectedDirOfProjectToOpen(dirStr);
}

void MainWindow::aboutMessageBox()
{
    auto result = QMessageBox::information(this, tr("About"),
                             tr("%1\nVersion: %2\nContributors: %3")
                             .arg(AppInfo::DESCRIPTION)
                             .arg(AppInfo::VERSION)
                             .arg(AppInfo::CONTRIBUTORS));
    Q_UNUSED(result)
}

void MainWindow::updateProjectTree()
{
    m_pFSModel->setRootPath(m_pProject->dir());
    ui->projectTree->setRootIndex(m_pFSModel->index(m_pProject->dir()));
}

void MainWindow::onProjectTreeItemClicked(const QModelIndex &index)
{
    QString filePath = m_pFSModel->filePath(index);
    if (QFileInfo(filePath).isFile()) {
        openDiagram(filePath);
    }
}

void MainWindow::stopWorkerThreads()
{
    QThread *pMainThread = QThread::currentThread();
    QList<QThread *> workerThreads = findChildren<QThread *>();
    for (auto pThread : workerThreads) {
        pThread->quit();
    }
    for (auto pThread : workerThreads) {
        while (pThread->isRunning() || !pThread->isFinished()) {
            pMainThread->msleep(100);
        }
    }
}

void MainWindow::setupMenubar() const
{
    connect(ui->actionOpen_Project, &QAction::triggered,
            this, &MainWindow::openProjectDialog);
    connect(ui->actionAbout, &QAction::triggered,
            this, &MainWindow::aboutMessageBox);
    connect(ui->actionQuit, &QAction::triggered,
            this, &MainWindow::quitApplication);
}

void MainWindow::setupToolbar() const
{

}

void MainWindow::setupProjectTree() const
{
    auto tree = ui->projectTree;
    tree->setModel(m_pFSModel);
    tree->setHeaderHidden(true);
    for (int i = 1; i < m_pFSModel->columnCount(); ++i) {
        tree->hideColumn(i);
    }
}

void MainWindow::setupFileList() const
{

}

void MainWindow::setupObjectsHierarchy() const
{

}

void MainWindow::setupObjectInspector() const
{

}
