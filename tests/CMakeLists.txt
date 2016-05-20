project( gtree_test CXX )

cmake_minimum_required( VERSION 3.5 )

find_package( Boost REQUIRED COMPONENTS unit_test_framework )

include_directories( ${Boost_INCLUDE_DIRS} )
link_directories( ${Boost_LIBRARY_DIRS} )

file( GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cxx" )

add_executable( ${PROJECT_NAME} ${SOURCES} )
set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14 )
set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON )

target_link_libraries( ${PROJECT_NAME} PRIVATE gtree )
target_link_libraries( ${PROJECT_NAME} PRIVATE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} )

add_test( unit_tests ${PROJECT_NAME} )

