cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(SQLite3 REQUIRED)

add_compile_options(-std=c++11 -pipe -Wall -Wextra -Wshadow -pedantic)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -march=native -fomit-frame-pointer")

add_library(${PROJECT_NAME} SHARED exceptions.cpp functions.cpp objects.cpp)
target_link_libraries(${PROJECT_NAME} ${SQLITE3_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES sqlite3pp.hpp DESTINATION include)
