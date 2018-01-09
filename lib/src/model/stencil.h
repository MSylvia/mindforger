/*
 concept_stencil.h     MindForger thinking notebook

 Copyright (C) 2016-2018 Martin Dvorak <martin.dvorak@mindforger.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef M8R_CONCEPT_STENCIL_H_
#define M8R_CONCEPT_STENCIL_H_

#include <string>
#include <vector>

#include "resource_types.h"

namespace m8r {

/**
 * @brief Outline or Note stencil.
 */
class Stencil {
private:
    const ResourceType type;
    const std::string filePath;
    const std::string name;
    // IMPROVE - rename variable to indicate it's stencil file content
    std::string* content;
public:
    explicit Stencil(const std::string filePath, ResourceType type=ResourceType::OUTLINE);
    Stencil(const std::string filePath, const std::string name, ResourceType type=ResourceType::OUTLINE);
    Stencil(const Stencil&) = delete;
    Stencil(const Stencil&&) = delete;
    Stencil &operator=(const Stencil&) = delete;
    Stencil &operator=(const Stencil&&) = delete;
    ~Stencil();

    ResourceType getType(void) const;
    const std::string& getFilePath(void) const;
    const std::string& getName(void) const;
    const std::string* getStencil(void) const;
    void setContent(std::string* content);
};

} /* namespace m8r */

#endif /* M8R_CONCEPT_STENCIL_H_ */