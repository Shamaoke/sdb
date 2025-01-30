
add_library(libsdb libsdb.cpp)

set_target_properties(
  libsdb
  PROPERTIES OUTPUT_NAME sdb
)

target_include_directories(
  libsdb
  PRIVATE include
  PUBLIC ${CMAKE_SOURCE_DIR}/include
)

