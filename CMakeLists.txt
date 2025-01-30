
##
## ::: SDB build management file :::
##

cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_COMPILER clang++)

add_compile_options(-std=c++23)

add_link_options(-fuse-ld=lld)

project(sdb LANGUAGES CXX)

include(CTest)

add_subdirectory(src)
add_subdirectory(tools)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()

