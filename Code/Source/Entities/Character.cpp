// #pragma once

#include "Code/Include/Entities/Character.h"

Character::Character(): m_id(-1)
{
} 

Character::Character(int64_t id): m_id(id) 
{
}

const int64_t& Character::GetID() const
{
    return m_id;
}