#pragma once

#include <cstdint>
#include <odb/core.hxx>
#include <odb/forward.hxx>
#include <string>
#include <memory>

#pragma db object
class Item 
{
private:
    friend class odb::access;

    #pragma db id auto
    int64_t m_id;
    std::string m_name;
public:
    Item();
    Item(int64_t id, std::string name);

    const int64_t& GetID() const;
    const std::string& GetName() const;
};