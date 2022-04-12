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

#ifndef PREFERENCES_EDITOR_DRIVESWIDGET_H
#define PREFERENCES_EDITOR_DRIVESWIDGET_H

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class DrivesWidget; }
QT_END_NAMESPACE

namespace preferences_editor
{
    class DrivesWidgetPrivate;

    class DrivesWidget : public QWidget
    {
        Q_OBJECT

    public:
        DrivesWidget(QStandardItemModel& model, QItemSelectionModel& selectionModel, QWidget *parent = 0);
        ~DrivesWidget();

    private:
        Ui::DrivesWidget *ui;
        DrivesWidgetPrivate* d;

    private:
        DrivesWidget(const DrivesWidget&)            = delete;   // copy ctor
        DrivesWidget(DrivesWidget&&)                 = delete;   // move ctor
        DrivesWidget& operator=(const DrivesWidget&) = delete;   // copy assignment
        DrivesWidget& operator=(DrivesWidget&&)      = delete;   // move assignment

    private:
        void setupModelMapper();
    };
}

#endif // PREFERENCES_EDITOR_DRIVESWIDGET_H
