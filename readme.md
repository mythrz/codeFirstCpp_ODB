# About

Sample code (Hello World) that generates a code-first database with C++ classes through google-tests. For testing purposes only

Their Official website can be found here[https://codesynthesis.com/products/odb/](https://codesynthesis.com/products/odb/)

The database is created and saved at ../build/linux/Debug/test.db

### Requirements Archlinux EOS

clang, gcc, git, cmake, base-devel, gtest, sqlite, odb, libodb, libodb-sqlite (adapt this to your OS)

```
sudo pacman -S sqlite gtest cmake base-devel
yay -S odb libodb libodb-sqlite
```

---
---
---

# Notes

### Configuration, build, debug

CMakeUserPresets.json file included. Make sure you adapt it to your needs. Also, ODB developers use build2, not CMake.

launch.json file included. Make sure you adapt it too.

---

### ODB generated files

The following command is what generates the odb-generated-classes that bride the cpp-classes and the database. This was moved to cmake/OdbCompile.cmake file. Every time you configure, the files are generated.

```
odb -d sqlite --std c++20 --generate-query --generate-schema --output-dir Code/odb Code/Include/Entities/Character.h
```

---

### Roadmap

- [x] CMake instead of build2
- [x] Clang
- [x] Google Tests instead of main to generate the database
- [x] SQLite
- [x] Hello world. Basics of code first with odb
- [ ] 1:1 relationship
- [ ] 1:M relationship
- [ ] Explore possibility of a single file having all the bloat-odb-code, instead of having classes annotated with #pragma odb (like a c# context)
- [ ] Outros

---
---
---