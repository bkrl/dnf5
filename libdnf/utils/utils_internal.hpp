/*
Copyright Contributors to the libdnf project.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2.1 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef LIBDNF_UTILS_UTILS_INTERNAL_HPP
#define LIBDNF_UTILS_UTILS_INTERNAL_HPP


#include <ctype.h>

#include <cstring>
#include <string>


namespace libdnf::utils {

inline bool is_glob_pattern(const char * pattern) {
    return strpbrk(pattern, "*[?") != nullptr;
}

/// @brief Test if pattern is file path
/// Return true if pattern start with "/" or pattern[0] == '*' && pattern[1] == '/'
static inline bool is_file_pattern(const std::string & pattern) {
    return pattern[0] == '/' || (pattern[0] == '*' && pattern[1] == '/');
}

inline std::string to_lowercase(const std::string & source) {
    auto length = source.size();
    std::string result;
    result.reserve(length);
    for (unsigned index = 0; index < length; ++index) {
        result += static_cast<char>(tolower(source[index]));
    }
    return result;
}


}  // namespace libdnf::utils


#endif  // LIBDNF_UTILS_UTILS_INTERNAL_HPP
