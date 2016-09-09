TEMPLATE = subdirs
SUBDIRS = sqlite3 sqlite3pp

sqlite3.subdir = lib/sqlite3
sqlite3pp.subdir = src

sqlite3pp.depends = sqlite3