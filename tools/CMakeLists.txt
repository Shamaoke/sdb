
add_executable(sdb sdb.cpp)

set_target_properties(
  sdb
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/_/bin
)

target_link_libraries(sdb PRIVATE libsdb PkgConfig::readline)

