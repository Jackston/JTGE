project(jtge)

file (GLOB_RECURSE SOURCE private/source/*.cpp)
list(FILTER SOURCE EXCLUDE REGEX "source.*win32.*|source.*linux.*") 

if(UNIX) # possible alternative -  if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    file (GLOB_RECURSE RENDERER_SRC private/source/Renderer/linux/*.cpp)
elseif(WIN32) # alt - elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    file (GLOB_RECURSE RENDERER_SRC private/source/Renderer/win32/*.cpp)
endif()

list(APPEND SOURCE ${RENDERER_SRC})

add_library(${PROJECT_NAME} STATIC ${SOURCE})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${JTGE_ROOT}/source/include
    PRIVATE ${JTGE_ROOT}/source/private/include
)