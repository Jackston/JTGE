project(simple_game)

file (GLOB_RECURSE SOURCE ./*cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} PRIVATE ${JTGE_ROOT}/source/include)
target_link_libraries(${PROJECT_NAME} jtge)