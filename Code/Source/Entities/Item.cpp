#include "Code/Include/Entities/Item.h"

Item::Item(): m_id(-1), m_name("")
{
}

Item::Item(int64_t id, std::string name): m_id(id), m_name(name)
{
}

const int64_t& Item::GetID() const
{
    return m_id;
}

const std::string& Item::GetName() const
{
    return m_name;
}