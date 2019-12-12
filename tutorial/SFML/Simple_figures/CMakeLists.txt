cmake_minimum_required (VERSION 3.8)
project (SimpleFigures)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Compile executable from source files in SOURCES variable
add_executable(SimpleFigures ${SOURCES}) 

set(SFML_DIR "/home/rustam/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(SimpleFigures sfml-graphics)

install (TARGETS SimpleFigures DESTINATION bin)