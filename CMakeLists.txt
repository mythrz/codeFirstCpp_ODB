cmake_minimum_required(VERSION 3.10)
project(CharacterLoadoutTests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "clang++")


# built-in CMake support packages
find_package(GTest REQUIRED)
find_package(PkgConfig REQUIRED)
# These do NOT have built-in CMake support
pkg_check_modules(LIBODB REQUIRED IMPORTED_TARGET libodb)
pkg_check_modules(LIBODB_SQLITE REQUIRED IMPORTED_TARGET libodb-sqlite)
pkg_check_modules(SQLITE3 REQUIRED IMPORTED_TARGET sqlite3)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ODB_INCLUDE_DIRS}
    ${SQLite3_INCLUDE_DIRS}
    ${GTEST_INCLUDE_DIRS}
)
link_directories(
    ${ODB_LIBRARY_DIRS}
    ${SQLite3_LIBRARY_DIRS}
    ${GTEST_LIBRARY_DIRS}
)

add_executable(CharacterLoadoutTests
    tests/CharacterLoadoutTest001.cpp
    Code/Include/Entities/Character.h
    Code/Source/Entities/Character.cpp
    Code/Include/Entities/Item.h
    Code/Source/Entities/Item.cpp
    Code/Include/Helper/DB_Helper.h
    Code/Source/Helper/DB_Helper.cpp
    # Character.hxx
    # Character-odb.cxx
    # Character-odb.hxx
    # Character-odb.ixx

    # schema-odb.cxx
    # schema-odb.hxx
    # schema-odb.ixx
)

# This will help -odb generated files find header files (e.g., Character.h). It will not work without it, because the generated files are inside a different folder
target_include_directories(CharacterLoadoutTests PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/Code/Include/Entities"
)

# Generate ODB files
include(cmake/OdbCompile.cmake)
odb_compile(CharacterLoadoutTests 
    "${CMAKE_CURRENT_SOURCE_DIR}/Code/Include/Entities/Character.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Code/odb"
)
odb_compile(CharacterLoadoutTests 
    "${CMAKE_CURRENT_SOURCE_DIR}/Code/Include/Entities/Item.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Code/odb"
)

target_link_libraries(CharacterLoadoutTests
    PkgConfig::LIBODB
    PkgConfig::LIBODB_SQLITE
    PkgConfig::SQLITE3 # SQLite3::SQLite3
    GTest::GTest
    GTest::Main
)

enable_testing()

add_test(NAME CharacterLoadoutTest COMMAND CharacterLoadoutTests)

