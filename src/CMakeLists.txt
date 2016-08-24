cmake_minimum_required(VERSION 3.0)


add_compile_options(-std=c++11 -pipe -Wall -Wextra -Wshadow -pedantic)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -march=native -fomit-frame-pointer")
set(SQLITE3PP_SOURCES exceptions.cpp functions.cpp objects.cpp)


add_library(${PROJECT_NAME}-static STATIC ${SQLITE3PP_SOURCES})
target_link_libraries(${PROJECT_NAME}-static ${SQLITE_STATIC_NAME})

install(TARGETS ${PROJECT_NAME}-static DESTINATION lib)
install(FILES sqlite3pp.hpp DESTINATION include)
