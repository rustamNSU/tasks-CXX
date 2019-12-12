cmake_minimum_required (VERSION 3.8)

project (Game)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)  
add_executable(Game ${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp)
target_link_libraries(Game GameOfLife)

install (TARGETS Game DESTINATION bin)

add_executable(Graphic ${CMAKE_CURRENT_SOURCE_DIR}/Graphic.cpp)

set(SFML_DIR "/home/rustam/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(Graphic GameOfLife sfml-graphics)

install (TARGETS Graphic DESTINATION bin)