/*
 * This file is part of Notepad Next.
 * Copyright 2022 Justin Dailey
 *
 * Notepad Next is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Notepad Next is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Notepad Next.  If not, see <https://www.gnu.org/licenses/>.
 */


#ifndef FOLDERASWORKSPACEDOCK_H
#define FOLDERASWORKSPACEDOCK_H

#include <QDockWidget>
#include <QAction>
#include <QDir>

namespace Ui {
class FolderAsWorkspaceDock;
}

class QFileSystemModel;

class FolderAsWorkspaceDock : public QDockWidget
{
    Q_OBJECT

public:
    explicit FolderAsWorkspaceDock(QWidget *parent = nullptr);
    ~FolderAsWorkspaceDock();

    void setRootPath(const QString dir);
    QString rootPath() const;

    void setFilter(const QDir::Filters filter);
    QDir::Filters filter() const;

signals:
    void fileDoubleClicked(const QString &filePath);

private:
    Ui::FolderAsWorkspaceDock *ui;

    QFileSystemModel *model;
    
    QAction* m_pHideFile;
};

#endif // FOLDERASWORKSPACEDOCK_H
