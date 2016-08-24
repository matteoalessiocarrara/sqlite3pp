cmake_minimum_required(VERSION 3.0)
project(sqlite3pp LANGUAGES CXX)


option(SQLITE3PP_BUILD_SHARED "" OFF)
option(SQLITE3PP_BUILD_STATIC "" ON)



if(SQLITE3PP_BUILD_SHARED)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")
find_package(SQLite3 REQUIRED)
endif()

if(SQLITE3PP_BUILD_STATIC)
add_subdirectory("${PROJECT_SOURCE_DIR}/lib/sqlite3")
endif()



add_subdirectory(src)