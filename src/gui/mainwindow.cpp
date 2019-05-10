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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Project *MainWindow::project() const
{
    return m_pProject;
}

void MainWindow::openProjectDialog()
{
    // TODO select dir and setup signals/slots
}

void MainWindow::setupMenubar() const
{
    connect(ui->actionOpen_Project, &QAction::triggered,
            this, &MainWindow::openProjectDialog);
    connect(ui->actionQuit, &QAction::triggered,
            QApplication::instance(), &QApplication::quit);
}

void MainWindow::setupToolbar() const
{

}
