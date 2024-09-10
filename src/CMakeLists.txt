file(GLOB_RECURSE PUBLIC_HEADERS "${PROJECT_SOURCE_DIR}/include/rpg_kata/*.hpp")
file(GLOB_RECURSE HEADERS        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB_RECURSE SOURCES        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(rpg_kata_lib ${PUBLIC_HEADERS}
                         ${HEADERS}
                         ${SOURCES})

target_include_directories(rpg_kata_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")
