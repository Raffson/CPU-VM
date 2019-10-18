# minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# set build/install variables
SET(BIN_INSTALL_LOCATION "${CMAKE_SOURCE_DIR}/bin")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++11")
if( CMAKE_CXX_COMPILER_ID STREQUAL "Clang"  AND CMAKE_HOST_APPLE )
	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++" )
endif()
ADD_SUBDIRECTORY(src)

# small settings overview
MESSAGE( STATUS "------> Settings: " )
MESSAGE( STATUS "------>    CMAKE_BINARY_DIR           : ${CMAKE_BINARY_DIR}"     )
MESSAGE( STATUS "------>    BIN_INSTALL_LOCATION       : ${BIN_INSTALL_LOCATION}" )
MESSAGE( STATUS "------>    CMAKE_CXX_COMPILER         : ${CMAKE_CXX_COMPILER}"   )
MESSAGE( STATUS "------>    CMAKE_CXX_FLAGS            : ${CMAKE_CXX_FLAGS}"	  )
