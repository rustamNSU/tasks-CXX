cmake_minimum_required (VERSION 3.8)

# Internal name of the project
project (GameOfLife)
file(GLOB_RECURSE SOURCES
       ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

file(GLOB_RECURSE HEADERS
       ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library (GameOfLife ${SOURCES})
target_include_directories (GameOfLife PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
install(TARGETS GameOfLife DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)