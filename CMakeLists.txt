#[[------------------------------------------

	--------------------------------
	sg-0 CMake Script
	--------------------------------
	
	Project: Generic

---------------------------------------------]]# 

cmake_minimum_required( VERSION 3.10 FATAL_ERROR )
set(PROJECT_NAME stack)
project( ${PROJECT_NAME} CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_CXX_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")

include( CTest )
enable_testing()

add_subdirectory( src/${PROJECT_NAME} )
add_subdirectory( test/googletest )

set( TEST_SRC
	test/tests.cpp
)

add_executable( ${PROJECT_NAME} ${TEST_SRC} )

target_include_directories( ${PROJECT_NAME} PRIVATE 
	src/${PROJECT_NAME}
)

target_link_libraries( ${PROJECT_NAME} PUBLIC
	STACK
	gtest_main
	gcov
)

add_test(
	NAME ${PROJECT_NAME}
	COMMAND ${PROJECT_NAME}
)
