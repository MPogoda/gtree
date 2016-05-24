project( bobfinder CXX )

cmake_minimum_required( VERSION 3.5 )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

add_subdirectory( gtree )

enable_testing()
add_subdirectory( tests )

add_executable( ${PROJECT_NAME} main.cxx )
target_link_libraries( ${PROJECT_NAME} gtree )

set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14 )
set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON )
