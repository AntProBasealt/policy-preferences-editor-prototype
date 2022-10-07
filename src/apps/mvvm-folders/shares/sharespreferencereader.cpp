/***********************************************************************************************************************
**
** Copyright (C) 2022 BaseALT Ltd. <org@basealt.ru>
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

#include "sharespreferencereader.h"

#include "schemas/sharesschema.h"
#include "sharesmodelbuilder.h"

namespace mvvm_folders
{
SharesPreferenceReader::SharesPreferenceReader()
    : BasePreferenceReader("Shares")
{}

std::unique_ptr<PreferencesModel> SharesPreferenceReader::createModel(std::istream &input)
{
    auto schema       = NetworkShareSettings_(input, ::xsd::cxx::tree::flags::dont_validate);
    auto modelBuilder = std::make_unique<SharesModelBuilder>();
    return modelBuilder->schemaToModel(schema);
}

} // namespace mvvm_folders
