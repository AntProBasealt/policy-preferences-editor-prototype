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

#include "tabledetailswidget.h"
#include "ui_tabledetailswidget.h"

#include "../shortcuts/shortcutscontaineritem.h"

#include <mvvm/factories/viewmodelfactory.h>
#include <mvvm/model/compounditem.h>
#include <mvvm/model/sessionmodel.h>
#include <mvvm/signals/itemmapper.h>
#include <mvvm/viewmodel/defaultviewmodel.h>
#include <mvvm/viewmodel/propertyviewmodel.h>
#include <mvvm/viewmodel/propertytableviewmodel.h>
#include <mvvm/viewmodel/topitemsviewmodel.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>
#include <mvvm/viewmodel/standardviewitems.h>

namespace mvvm_folders
{

TableDetailsWidget::TableDetailsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TableDetailsWidget())
    , view_model(nullptr)
    , delegate(std::make_unique<ModelView::ViewModelDelegate>())
    , mapper(nullptr)
{
    ui->setupUi(this);
}

TableDetailsWidget::~TableDetailsWidget()
{
    delete ui;
}

void TableDetailsWidget::setModel(ModelView::SessionModel *model)
{
    view_model = std::make_unique<ModelView::PropertyTableViewModel>(model);

    ui->treeView->setModel(view_model.get());
    ui->treeView->setItemDelegate(delegate.get());
    ui->treeView->header()->setSectionResizeMode(QHeaderView::Stretch);

    ui->treeView->selectionModel()->select(QModelIndex(), QItemSelectionModel::Select);

    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeView, &QTreeView::customContextMenuRequested, this, &TableDetailsWidget::onContextMenuRequest);
}

void TableDetailsWidget::onContextMenuRequest(const QPoint &point)
{
    auto treeView = qobject_cast<QTreeView*>(sender());

    QModelIndex index = treeView->indexAt(point);

    auto view_item = view_model->itemFromIndex(index);

    QMenu menu;

    if (!view_item)
    {
        auto addItemAction = menu.addAction("Add item");
        auto add_item = [&]() {
            // TODO: Add item type selection.
            auto newItem = view_model->sessionModel()->insertNewItem("ShortcutsContainerItem", view_model->sessionModel()->rootItem());
            if (auto shortcutContainer = dynamic_cast<ShortcutsContainerItem*>(newItem))
            {
                shortcutContainer->setupListeners();
            }

        };
        connect(addItemAction, &QAction::triggered, add_item);
    }
    else
    {
        auto item = view_item->item()->parent();
        auto tagrow = item->tagRow();

        // inserting item of same type after given item
        auto addItemAction = menu.addAction("Add item");
        auto add_item = [&]() {
            view_model->sessionModel()->insertNewItem(item->modelType(), item->parent(), tagrow.next());
        };
        connect(addItemAction, &QAction::triggered, add_item);

        // removing item under the mouse
        auto removeItemAction = menu.addAction("Remove item");
        auto remove_item = [&]() { view_model->sessionModel()->removeItem(item->parent(), tagrow); };
        connect(removeItemAction, &QAction::triggered, remove_item);
    }

    menu.exec(treeView->mapToGlobal(point));
}

}
