cmake_minimum_required(VERSION 3.5)

set(JTGE_ROOT ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Root path of JTGE project")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${JTGE_ROOT}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${JTGE_ROOT}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${JTGE_ROOT}/bin)

option(BUILD_EXAMPLES "Build examples" OFF)

add_subdirectory(source)

if(BUILD_EXAMPLES)
    add_subdirectory(doc/example)
endif()