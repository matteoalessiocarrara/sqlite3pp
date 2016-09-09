TARGET=sqlite3pp

TEMPLATE = lib
CONFIG = static debug c++11
unix:LIBS = -L../lib/sqlite3/ -lsqlite3
debug:QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -pedantic

SOURCES = exceptions.cpp functions.cpp objects.cpp
HEADERS = sqlite3pp.hpp
