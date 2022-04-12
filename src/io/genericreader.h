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

#ifndef PREFERENCES_EDITOR_GENERIC_READER_H
#define PREFERENCES_EDITOR_GENERIC_READER_H

#include "io.h"

#include <memory>
#include <string>

namespace io {
    class PREFERENCES_EDITOR_IO_EXPORT GenericReader
    {
    public:
        virtual ~GenericReader() = default;

        template<typename TData, typename TFormat>
        std::unique_ptr<TData> load(const std::string& fileName);

        template<typename TData, typename TFormat>
        std::unique_ptr<TData> load(std::istream& file, const std::string& pluginName);
    };
}

#include "genericreader.inl"

#endif // PREFERENCES_EDITOR_GENERIC_READER_H
