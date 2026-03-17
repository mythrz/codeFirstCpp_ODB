#pragma once

#include <cstdint>
#include <odb/core.hxx>
#include <odb/forward.hxx>
#include <string>
#include <memory>
#include <vector>
#include "Item.h"
#include "Character.h"

#pragma db object
class Container 
{
private:
    friend class odb::access;

    #pragma db id auto
    int64_t m_id;
public:
    Container();
    Container(int64_t id);

    #pragma db value_not_null unordered
    std::vector<std::shared_ptr<Item>> m_items;

    #pragma db not_null
    std::shared_ptr<Character> m_character;
};