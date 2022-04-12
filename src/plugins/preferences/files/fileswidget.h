/***********************************************************************************************************************
**
** Copyright (C) 2021 BaseALT Ltd. <org@basealt.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#ifndef PREFERENCES_EDITOR_FILESWIDGET_H
#define PREFERENCES_EDITOR_FILESWIDGET_H

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class FilesWidget; }
QT_END_NAMESPACE

namespace preferences_editor
{
    class FilesWidget : public QWidget
    {
        Q_OBJECT

    public:
        FilesWidget(QStandardItemModel& model, QItemSelectionModel& selectionModel, QWidget *parent = 0);
        ~FilesWidget();

    private:
        FilesWidget(const FilesWidget&)            = delete;   // copy ctor
        FilesWidget(FilesWidget&&)                 = delete;   // move ctor
        FilesWidget& operator=(const FilesWidget&) = delete;   // copy assignment
        FilesWidget& operator=(FilesWidget&&)      = delete;   // move assignment

    private:
        Ui::FilesWidget *ui;
    };
}

#endif // PREFERENCES_EDITOR_FILESWIDGET_H
