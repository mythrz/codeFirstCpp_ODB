#pragma once

#include <cstdint>
#include <odb/core.hxx>
#include <odb/forward.hxx>
#include <string>
#include <memory>
#include "Character.h"

#pragma db object
class Item 
{
private:
    friend class odb::access;

    #pragma db id auto
    int64_t m_id;

    int64_t m_characterID;
    std::string m_name;
public:
    Item();
    Item(int64_t id, int64_t characterID, std::string name, std::shared_ptr<Character> character);

    const int64_t& GetID() const;
    const int64_t& GetCharacterID() const;
    const std::string& GetName() const;

    #pragma db not_null
    std::shared_ptr<Character> m_character;
};