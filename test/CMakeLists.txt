
add_executable(tests tests.cpp)

set_target_properties(
  tests
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/_/bin/tests
)

target_link_libraries(tests PRIVATE libsdb Catch2::Catch2WithMain)

