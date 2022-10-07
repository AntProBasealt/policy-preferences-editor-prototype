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

#include "filespreferencereader.h"

#include "filesmodelbuilder.h"
#include "schemas/filesschema.h"

namespace mvvm_folders
{

FilesPreferenceReader::FilesPreferenceReader()
    : BasePreferenceReader("Files")
{
}

std::unique_ptr<PreferencesModel> FilesPreferenceReader::createModel(std::istream &input)
{
    auto files = Files_(input, ::xsd::cxx::tree::flags::dont_validate);
    auto modelBuilder = std::make_unique<FilesModelBuilder>();
    return modelBuilder->schemaToModel(files);
}

}
