project( bobfinder CXX )

cmake_minimum_required( VERSION 3.5 )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

add_subdirectory( gtree )

enable_testing()
add_subdirectory( tests )

