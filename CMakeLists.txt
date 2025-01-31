
##
## ::: SDB build management file :::
##

cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_COMPILER clang++)

add_compile_options(-std=c++23)

add_link_options(-fuse-ld=lld)

project(sdb LANGUAGES CXX)

find_package(PkgConfig REQUIRED)

pkg_check_modules(readline REQUIRED IMPORTED_TARGET readline)

include(CTest)

add_subdirectory(src)
add_subdirectory(tools)

if(BUILD_TESTING)
  find_package(Catch2 CONFIG REQUIRED)
  add_subdirectory(test)
endif()

