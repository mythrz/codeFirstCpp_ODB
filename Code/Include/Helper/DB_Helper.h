#include <string>
#include <memory>
#include <odb/core.hxx>

//! static helper to manage the database
namespace DB_Helper
{
    //! create empty SQLite database; generate schema/tables
    std::shared_ptr<odb::database> CreateDatabase(std::string path = "", std::string dbName = "test.db");

} /// DB_Helper  