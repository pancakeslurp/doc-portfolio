# Document
dev-environment-setup.md

# Purpose

Set up a real C++ development stack in Red Hat Enterprise Linux 10 (RHEL 10) or Rocky 10.

# Background

I'd been using Vim and GNOME Text Editor for editing code and manually using g++ to compile and git to push to Github. That obviously wasn't industry standard or sustainable practice. I also needed to integrate unit testing and version control.

# Summary

Package installation

```
sudo dnf update # Do this for good measure
sudo dnf install epel-release
sudo dnf config-manager --set-enabled crb
sudo dnf install gcc-toolset-14 cmake ninja-build gdb valgrind \
  clang clang-tools-extra cppcheck ccache lvoc doxygen
```

What is all this???

The core stack
* __CMake + Ninja__: Industry default build tools and what most other tools expect.
* __gdb + Valgrind__: Debugger (gdb) and leak checks (Valgrind).
* __clang-tidy + cppcheck__: Static analysis. Free equivalent to Coverity/Polyspace tools used by defense shops.
* __clang-format__: Formatting with committed `.clang-format`.
* __ctest__: Testing tool using GoogleTest/Catch2, baked into CMake.
* __gvoc/lvoc__: Branch coverage as practice for MC/DC-style thinking.
* __doxygen__: Documentation.

Editor: You can use Vim and add a language server by installing `clangd` from `clang-tools-extra` and use it through vim-lsp or coc.nvim. Offers completion, go-to-definition, and live diagnostics.

Alternatively, you can use VS Code, VSCodium (open source version of VS Code) with clangd, or just like notepad or GNOME Text Editor. It's your sanity, take care of it however you see fit.

## The Steps

1. Install packages.

```
sudo dnf install -y epel-release
sudo dnf config-manager --set-enabled crb
sudo dnf install -y gcc-toolset-14 cmake ninja-build gdb valgrind \
  clang clang-tools-extra cppcheck ccache lcov doxygen git
```

2. Activate new compiler.

```
source scl_source enable gcc-toolset-14
g++ --version
```

3. Create a project skeleton

mkdir -p ~/dev/hello/{src,include,tests} && cd ~/dev/hello
git init
printf 'build/\n.cache/\ncompile_commands.json\n' > .gitignore

Create these files:

```
.
├── CMakeLists.txt
├── include
│   └── greet.hpp
├── src
│   ├── greet.cpp
│   └── main.cpp
└── tests
    ├── CMakeLists.txt
    └── greet_test.cpp
```

The file contents are in the environments-cpp-stack-skeleton folder. It's a "Hello world" program with a unit test.

4. Write the base directory's CMakeLists.txt.

5. Add a test with GoogleTest.

See files: `tests/CMakeLists.txt`, `tests/greet_test.cpp`.

`FetchContent` (in `CMakeLists.txt`) downloads GoogleTest at configure time and needs an internet connection. If you want to use it offline:

```
sudo dnf install gtest-devel
```

Then swap in `find_package(GTest REQUIRED)` in place of FetchContent.

6. Build, run and test with sanitizers on.

```
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DSANITIZE=ON
cmake --build build
./build/hello
ctest --test-dir build --output-on-failure
ln -sf build/compile_commands.json .
```
7. Debug with gdb.

`gdb -tui ./build/hello`

Some useful commands include:
```
break main
run
next
step
print var
bt
continue
```

If you want to run a leak check without sanitizers, use a non-sanitized build with `valgrind --leak-check=full ./build/hello`.

8. Formatting and static analysis.
```
clang-format -style=LLVM -dump-config > .clang-format   # then edit to taste
clang-format -i src/*.cpp include/*.hpp tests/*.cpp

clang-tidy -p build src/*.cpp
cppcheck --enable=all --project=build/compile_commands.json
```
Fir a starting `.clang-tidy`, you can try:
`Checks: 'bugprone-*,modernize-*,performance-*,readability-*,cppcoreguidelines-*` 
Then you can get rid of annoying, verbose checks as needed.

9. Code coverage.

cmake -S . -B build-cov -G Ninja -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_CXX_FLAGS="--coverage -O0"
cmake --build build-cov && ctest --test-dir build-cov
lcov --capture --directory build-cov --output-file cov.info
genhtml cov.info --output-directory cov-report

Open `cov-report/index.html` in your browser.

10. Commit
```
git add -A && git commit -m "Initial CMake project with tests"
```
