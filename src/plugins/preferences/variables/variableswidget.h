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

#ifndef PREFERENCES_EDITOR_VARIABLESWIDGET_H
#define PREFERENCES_EDITOR_VARIABLESWIDGET_H

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class VariablesWidget; }
QT_END_NAMESPACE

namespace preferences_editor
{
    class VariablesWidget : public QWidget
    {
        Q_OBJECT

    public:
        VariablesWidget(QWidget *parent = 0);
        ~VariablesWidget();

    private:
        VariablesWidget(const VariablesWidget&)            = delete;   // copy ctor
        VariablesWidget(VariablesWidget&&)                 = delete;   // move ctor
        VariablesWidget& operator=(const VariablesWidget&) = delete;   // copy assignment
        VariablesWidget& operator=(VariablesWidget&&)      = delete;   // move assignment

    private:
        Ui::VariablesWidget *ui;
    };
}

#endif // PREFERENCES_EDITOR_VARIABLESWIDGET_H
