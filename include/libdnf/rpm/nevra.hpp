/*
Copyright (C) 2018-2020 Red Hat, Inc.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef LIBDNF_RPM_NEVRA_HPP
#define LIBDNF_RPM_NEVRA_HPP

#include <string>

namespace libdnf::rpm {

struct Nevra {
public:
    enum class Form { NEVRA = 1, NEVR = 2, NEV = 3, NA = 4, NAME = 5 };
    
    static constexpr int EPOCH_NOT_SET = -1;

    Nevra();

    bool parse(const std::string & nevra_str, Form form);
    void clear() noexcept;

    const std::string & get_name() const noexcept;
    int get_epoch() const noexcept;
    const std::string & get_version() const noexcept;
    const std::string & get_release() const noexcept;
    const std::string & get_arch() const noexcept;

    void set_name(const std::string & name);
    void set_epoch(int epoch);
    void set_version(const std::string & version);
    void set_release(const std::string & release);
    void set_arch(const std::string & arch);

    void set_name(std::string && name);
    void set_version(std::string && version);
    void set_release(std::string && release);
    void set_arch(std::string && arch);

    bool has_just_name() const;

private:
    std::string name;
    // TODO(jmracek) What about to store epoch as a string?
    int epoch;
    std::string version;
    std::string release;
    std::string arch;
};

inline Nevra::Nevra()
: epoch(EPOCH_NOT_SET) {}

inline const std::string & Nevra::get_name() const noexcept
{
    return name;
}

inline int Nevra::get_epoch() const noexcept
{
    return epoch;
}

inline const std::string & Nevra::get_version() const noexcept
{
    return version;
}

inline const std::string & Nevra::get_release() const noexcept
{
    return release;
}

inline const std::string & Nevra::get_arch() const noexcept {
    return arch;
}

inline void Nevra::set_name(const std::string & name)
{
    this->name = name;
}

inline void Nevra::set_epoch(int epoch)
{
    this->epoch = epoch;
}

inline void Nevra::set_version(const std::string & version)
{
    this->version = version;
}

inline void Nevra::set_release(const std::string & release)
{
    this->release = release;
}

inline void Nevra::set_arch(const std::string & arch)
{
    this->arch = arch;
}

inline void Nevra::set_name(std::string && name)
{
    this->name = std::move(name);
}

inline void Nevra::set_version(std::string && version)
{
    this->version = std::move(version);
}

inline void Nevra::set_release(std::string && release)
{
    this->release = std::move(release);
}

inline void Nevra::set_arch(std::string && arch)
{
    this->arch = std::move(arch);
}


}  // namespace libdnf::rpm

#endif  // LIBDNF_RPM_NEVRA_HPP