cmake_minimum_required(VERSION 3.5)
project(Roguelike101 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 0)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(Roguelike101 ${SOURCES})

target_include_directories(Roguelike101 PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Roguelike101 PRIVATE ${CMAKE_SOURCE_DIR}/lib)

find_package(libtcod CONFIG REQUIRED)
target_link_libraries(Roguelike101 PRIVATE libtcod::libtcod)
