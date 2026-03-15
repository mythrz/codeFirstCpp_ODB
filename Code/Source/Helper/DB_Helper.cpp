#include <memory>
#include <filesystem>
#include <odb/sqlite/database.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/transaction.hxx>

namespace DB_Helper
{
    std::shared_ptr<odb::database> CreateDatabase(std::string exePath, std::string dbName)
    {
        if (exePath.empty())
        {
             exePath = std::filesystem::canonical("/proc/self/exe").parent_path();
        }
        if (dbName.empty())
        {
            dbName = "test.db";
        }
        std::filesystem::path dbPath = std::filesystem::path(exePath) / dbName;

        std::shared_ptr<odb::database> db(
            new odb::sqlite::database(dbPath.string(), 
            SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE)
        );

        {
            odb::transaction t(db->begin());
            // This looks at the compiled-in ODB metadata to build your tables
            odb::schema_catalog::create_schema(*db);
            t.commit();
        }

        return db;
    }
}