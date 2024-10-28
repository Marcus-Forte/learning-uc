find_package(GTest REQUIRED)

add_executable(test_module
 src/test_module.cc)

target_link_libraries(test_module appLib)
target_include_directories(test_module PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_module gtest gmock)
gtest_discover_tests(test_module)