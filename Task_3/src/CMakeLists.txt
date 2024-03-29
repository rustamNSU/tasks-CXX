cmake_minimum_required (VERSION 3.8)

# Internal name of the project
project (Huffman)

# Find all *.cpp files in ${CMAKE_CURRENT_SOURCE_DIR}/ and put them in SOURCES variable
file(GLOB_RECURSE SOURCES
       ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Same with headers
file(GLOB_RECURSE HEADERS
       ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

# Include folder needed to compile this library
# Compiler will search headers in this folder only during this library build
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Compile library from source files in SOURCES variable
# add_library(<name> <type> <sources>)
# This is a static library
add_library (Huffman ${SOURCES})

# Include directories connected with this library
# Compiler will search headers in this folder when other library or executable is going to link with this library
target_include_directories (Huffman PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# target_link_libraries ()

# Where to install this library when "make install" command issued
install(TARGETS Huffman DESTINATION lib)

# Where to put headers when "make install" command issued
install(FILES ${HEADERS} DESTINATION include)