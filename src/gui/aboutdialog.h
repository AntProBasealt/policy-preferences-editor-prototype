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

#ifndef PREFERENCES_EDITOR_ABOUT_DIALOG_H
#define PREFERENCES_EDITOR_ABOUT_DIALOG_H

#include "gui.h"

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AboutDialog; }
QT_END_NAMESPACE

namespace preferences_editor
{
    class AboutDialog : public QDialog
    {
        Q_OBJECT
    public:
        // construction and destruction
        AboutDialog(QWidget *parent);
        ~AboutDialog();

    private:
        AboutDialog(const AboutDialog&)            = delete;   // copy ctor
        AboutDialog(AboutDialog&&)                 = delete;   // move ctor
        AboutDialog& operator=(const AboutDialog&) = delete;   // copy assignment
        AboutDialog& operator=(AboutDialog&&)      = delete;   // move assignment

    private:
        Ui::AboutDialog *ui;
    };


}

#endif//PREFERENCES_EDITOR_ABOUT_DIALOG_H
