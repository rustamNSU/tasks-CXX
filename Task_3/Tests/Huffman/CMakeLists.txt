cmake_minimum_required (VERSION 3.8)

project (HuffmanTest)

# Find all *.cpp files in ${CMAKE_CURRENT_SOURCE_DIR}/src/ and put them in SOURCES variable
file(GLOB_RECURSE SOURCES                           
       ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


# Include folder needed to compile this executable
# Compiler will search headers in this folder only during this executable build
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)  

# Compile executable from source files in SOURCES variable
add_executable(HuffmanTest ${CMAKE_CURRENT_SOURCE_DIR}/src/HuffmanTest.cpp)         
target_link_libraries(HuffmanTest Huffman)
install (TARGETS HuffmanTest DESTINATION bin)

# Compile executable from source files in SOURCES variable
add_executable(HuffmanDecode ${CMAKE_CURRENT_SOURCE_DIR}/src/HuffmanDecode.cpp)         
target_link_libraries(HuffmanDecode Huffman)
install (TARGETS HuffmanDecode DESTINATION bin)
