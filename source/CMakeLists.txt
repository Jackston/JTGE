project(jtge)

file (GLOB_RECURSE SOURCE private/source/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE})

target_include_directories(${PROJECT_NAME}
    PRIVATE ${JTGE_ROOT}/source/include
    PRIVATE ${JTGE_ROOT}/source/private/include
)