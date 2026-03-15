#include <cstdint>
#include "Code/Include/Entities/Character.h"
#include <gtest/gtest.h>
#include <odb/sqlite/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <memory>
#include <filesystem>

#include "Code/odb/Character-odb.hxx" // generated header
#include "Code/Include/Helper/DB_Helper.h"


//! Add a Character to the persistent database on disk
void AddCharacter(std::shared_ptr<odb::database>& db, const int64_t& id1)
{
    {
        Character c(id1);
        odb::transaction t(db->begin());
        db->persist(c); 
        t.commit();
    }
}
//! Read the character from the persistence database
void GetCharacter(std::shared_ptr<odb::database>& db, const int64_t& id1)
{
    {
        odb::transaction t(db->begin());
        
        // Find by Primary Key (id1)
        std::unique_ptr<Character> loaded_c(db->load<Character>(id1));

        ASSERT_NE(loaded_c, nullptr); // Ensure it isn't null
        EXPECT_EQ(loaded_c->GetID(), id1);
        
        t.commit();
    }
}
TEST(CharacterLoadoutTest, CreateCharacter) 
{
    std::shared_ptr<odb::database> db = DB_Helper::CreateDatabase("", "test.db");

    const int64_t id1 = 1;
    
    AddCharacter(db, id1);

    GetCharacter(db, id1);
}

