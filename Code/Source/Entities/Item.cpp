#include "Code/Include/Entities/Item.h"

Item::Item(): m_id(-1), m_characterID(-1), m_name(""), m_character(nullptr)
{
}

Item::Item(int64_t id, int64_t characterID, std::string name, std::shared_ptr<Character> character): m_id(id), m_characterID(characterID), m_name(name), m_character(character)
{
}

const int64_t& Item::GetID() const
{
    return m_id;
}

const int64_t& Item::GetCharacterID() const
{
    return m_characterID;
}

const std::string& Item::GetName() const
{
    return m_name;
}