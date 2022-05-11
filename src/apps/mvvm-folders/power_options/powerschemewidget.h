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

#ifndef MVVM_FOLDERS_POWER_SCHEME_WIDGET_H
#define MVVM_FOLDERS_POWER_SCHEME_WIDGET_H

#include "interfaces/preferenceswidgetinterface.h"

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class PowerSchemeWidget; }
QT_END_NAMESPACE

class QDataWidgetMapper;

namespace ModelView
{
class ViewModel;
class ViewModelDelegate;
class SessionItem;
}

namespace mvvm_folders
{

class PowerSchemeItem;

//! Folder item representation for editor.

class PowerSchemeWidget : public PreferenceWidgetInterface
{
public:
    Q_OBJECT

public:
    explicit PowerSchemeWidget(QWidget* parent = nullptr, PowerSchemeItem* item = nullptr);
    ~PowerSchemeWidget() override;

    void setItem(ModelView::SessionItem *item) override;

    bool validate() override;

public slots:
    void submit() override;

private slots:
    void on_actionComboBox_currentIndexChanged(int index);

private:
    PowerSchemeWidget(const PowerSchemeWidget&)            = delete;   // copy ctor
    PowerSchemeWidget(PowerSchemeWidget&&)                 = delete;   // move ctor
    PowerSchemeWidget& operator=(const PowerSchemeWidget&) = delete;   // copy assignment
    PowerSchemeWidget& operator=(PowerSchemeWidget&&)      = delete;   // move assignment

private:
    //!< Underlying item of this view.
    PowerSchemeItem* m_item {nullptr};

    std::unique_ptr<ModelView::ViewModel> view_model;
    std::unique_ptr<ModelView::ViewModelDelegate> delegate;
    std::unique_ptr<QDataWidgetMapper> mapper;

private:
    Ui::PowerSchemeWidget *ui {nullptr};
};

}

#endif//MVVM_FOLDERS_POWER_SCHEME_WIDGET_H
