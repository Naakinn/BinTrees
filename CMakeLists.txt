cmake_minimum_required(VERSION 3.10)
 
project(bintrees VERSION 1.0)
include(GNUInstallDirs)

add_library(bintrees src/bintree.cpp)
 
set_target_properties(bintrees PROPERTIES 
	VERSION ${PROJECT_VERSION}
	PUBLIC_HEADER src/include/bintree.h
)
 
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

target_include_directories(bintrees PRIVATE src/include) 
 
install(
    TARGETS bintrees
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
) 
