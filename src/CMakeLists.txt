cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(SQLite3 REQUIRED)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

add_library(${PROJECT_NAME} SHARED exceptions.cpp functions.cpp objects.cpp)
target_link_libraries(${PROJECT_NAME} ${SQLITE3_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES sqlite3pp.hpp DESTINATION include)