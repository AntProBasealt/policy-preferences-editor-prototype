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

#include "devicewidgettest.h"

#include <fstream>

#include <device/deviceitem.h>
#include <device/devicewidget.h>
#include <device/devicemodelbuilder.h>
#include <device/devicecontaineritem.h>

const std::string dataPath = "../../../../../../data/preferences/machine/control_panel/network_options/";

using namespace mvvm_folders;

namespace tests
{
std::unique_ptr<DeviceWidget> DeviceWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<DeviceWidget> deviceWidget = nullptr;

    try {
        auto files = Devices_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<DeviceModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        deviceWidget = std::make_unique<DeviceWidget>();
        auto containerItem = model->topItem();
        auto deviceContainer = dynamic_cast<DeviceContainerItem*>(containerItem);

        if (!deviceContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        deviceWidget->setItem(deviceContainer->children().back());
        deviceWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return deviceWidget;
}

void DeviceWidgetTest::actionState()
{
    QFETCH(QString, dataPath);
    QFETCH(QString, actionComboBoxState);
    QFETCH(bool, deviceClassLineEditState);
    QFETCH(bool, deviceTypeLineEditState);
    QFETCH(bool, deviceClassLabelState);
    QFETCH(bool, deviceTypeLabelState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto actionComboBox         = widget->findChild<QComboBox*> ("actionComboBox");
    auto deviceClassLineEdit    = widget->findChild<QLineEdit*> ("deviceClassLineEdit");
    auto deviceTypeLineEdit     = widget->findChild<QLineEdit*> ("deviceTypeLineEdit");
    auto deviceClassLabel       = widget->findChild<QLabel*>    ("deviceClassLabel");
    auto deviceTypeLabel        = widget->findChild<QLabel*>    ("deviceTypeLabel");

    QTest::qWait(1000);

    QVERIFY(actionComboBox);
    QVERIFY(deviceTypeLineEdit);
    QVERIFY(deviceClassLineEdit);
    QVERIFY(deviceClassLabel);
    QVERIFY(deviceTypeLabel);

    QCOMPARE(actionComboBox     ->currentText(),    actionComboBoxState);
    QCOMPARE(deviceTypeLineEdit ->isEnabled(),      deviceTypeLineEditState);
    QCOMPARE(deviceClassLineEdit->isEnabled(),      deviceClassLineEditState);
    QCOMPARE(deviceClassLabel   ->isEnabled(),      deviceClassLabelState);
    QCOMPARE(deviceTypeLabel    ->isEnabled(),      deviceTypeLabelState);
}

void DeviceWidgetTest::actionState_data()
{
    QTest::addColumn<bool>("dataPath");
    QTest::addColumn<bool>("actionComboBoxState");
    QTest::addColumn<bool>("deviceTypeLineEditState");
    QTest::addColumn<bool>("attributesTableViewState");
    QTest::addColumn<bool>("deviceClassLabelState");
    QTest::addColumn<bool>("deviceTypeLabelState");

    QTest::addRow("Device")  << QString::fromStdString(dataPath + "device.xml") << "Use this device (enable)" << true << true << true << true ;
}

}

QTEST_MAIN(tests::DeviceWidgetTest)

