  find_program(FORMATTER clang-format)
  if(FORMATTER)
    file(GLOB_RECURSE SRC_FILES
      ${CMAKE_SOURCE_DIR}/src/*.cc
      ${CMAKE_SOURCE_DIR}/include/*.hh)
    add_custom_target(code-format ALL
    clang-format -i ${SRC_FILES})
  endif()