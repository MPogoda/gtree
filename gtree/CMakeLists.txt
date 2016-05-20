project( gtree CXX )

cmake_minimum_required( VERSION 3.5 )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

find_package( Boost REQUIRED COMPONENTS date_time )

include_directories( ${Boost_INCLUDE_DIRS} )
link_directories( ${Boost_LIBRARY_DIRS} )

file( GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cxx" )
add_library( ${PROJECT_NAME} ${SOURCES} )

set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14 )
set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON )

target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )

