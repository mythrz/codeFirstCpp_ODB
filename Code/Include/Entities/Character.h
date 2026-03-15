#pragma once

#include <cstdint>
#include <odb/core.hxx>
#include <odb/forward.hxx>

#pragma db object
class Character
{
private:
    friend class odb::access;

    #pragma db id auto /// auto will assign a new ID in the database, and ignore the input
    int64_t m_id;
public:
    Character();
    Character(int64_t id);

    const int64_t& GetID() const;
};