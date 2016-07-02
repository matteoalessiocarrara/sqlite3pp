cmake_minimum_required(VERSION 3.0)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "../cmake/")

find_package(SQLite3 REQUIRED)

add_library(${PROJECT_NAME} SHARED sqlite3pp.cpp)
target_link_libraries(${PROJECT_NAME} ${SQLITE3_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES sqlite3pp.hpp DESTINATION include)