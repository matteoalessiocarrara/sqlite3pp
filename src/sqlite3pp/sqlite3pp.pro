TARGET = sqlite3pp

TEMPLATE = lib
CONFIG = static debug c++11

SOURCES = exceptions.cpp functions.cpp objects.cpp
HEADERS = sqlite3pp.hpp

debug:QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -pedantic
