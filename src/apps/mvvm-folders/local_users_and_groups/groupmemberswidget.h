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

#ifndef MVVM_FOLDERS_GROUPMEMBERS_WIDGET_H
#define MVVM_FOLDERS_GROUPMEMBERS_WIDGET_H

#include "interfaces/preferenceswidgetinterface.h"

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class GroupMembersWidget; }
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

class GroupMemberItem;
class GroupMembersContainerItem;

//! Folder item representation for editor.

class GroupMembersWidget : public PreferenceWidgetInterface
{
public:
    Q_OBJECT

public:
    explicit GroupMembersWidget(QWidget* parent = nullptr, GroupMembersContainerItem* item = nullptr);
    ~GroupMembersWidget() override;

    void setItem(ModelView::SessionItem *item) override;

    bool validate() override;

public slots:
    void submit() override;

private slots:
    void on_addPushButton_clicked();
    void on_removePushButton_clicked();
    void on_changePushButton_clicked();

private:
    GroupMembersWidget(const GroupMembersWidget&)            = delete;   // copy ctor
    GroupMembersWidget(GroupMembersWidget&&)                 = delete;   // move ctor
    GroupMembersWidget& operator=(const GroupMembersWidget&) = delete;   // copy assignment
    GroupMembersWidget& operator=(GroupMembersWidget&&)      = delete;   // move assignment

private:
    //!< Underlying item of this view.
    GroupMembersContainerItem* m_item {nullptr};
    QModelIndex* m_selectedItem {nullptr};

    std::unique_ptr<ModelView::ViewModel> view_model;
    std::unique_ptr<ModelView::ViewModelDelegate> delegate;
    std::unique_ptr<QDataWidgetMapper> mapper;

private:
    Ui::GroupMembersWidget *ui {nullptr};
};

}

#endif//MVVM_FOLDERS_GROUPMEMBERS_WIDGET_H
