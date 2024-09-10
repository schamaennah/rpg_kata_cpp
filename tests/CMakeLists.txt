# Setting CPM
set(CPM_DOWNLOAD_LOCATION ${CMAKE_BINARY_DIR}/CPM.cmake)

file(DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/cpm.cmake
        ${CPM_DOWNLOAD_LOCATION})

include(${CPM_DOWNLOAD_LOCATION})

# Setting Catch2
CPMAddPackage("gh:catchorg/Catch2@3.7.1")
find_package(Catch2 REQUIRED)

# Enable testing
enable_testing()

set(CATCH_CONFIG_COLOUR_WIN32 ON)

file(GLOB_RECURSE TEST_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB_RECURSE TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(rpg_kata_tests ${TEST_HEADERS} ${TEST_SOURCES})

target_include_directories(rpg_kata_tests PRIVATE ../src)
target_link_libraries(rpg_kata_tests Catch2::Catch2WithMain rpg_kata_lib)
