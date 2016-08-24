cmake_minimum_required(VERSION 3.0)
project(sqlite3pp LANGUAGES CXX)

add_subdirectory("${PROJECT_SOURCE_DIR}/lib/sqlite3")
add_subdirectory(src)