#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  Copyright 2016 Matteo Alessio Carrara <sw.matteoac@gmail.com>
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.


# https://sqlite.org/rescode.html

not_error_codes = ["SQLITE_OK", "SQLITE_ROW", "SQLITE_DONE"]


raw_primary_result_codes = """
    SQLITE_ABORT (4)
    SQLITE_AUTH (23)
    SQLITE_BUSY (5)
    SQLITE_CANTOPEN (14)
    SQLITE_CONSTRAINT (19)
    SQLITE_CORRUPT (11)
    SQLITE_DONE (101)
    SQLITE_EMPTY (16)
    SQLITE_ERROR (1)
    SQLITE_FORMAT (24)
    SQLITE_FULL (13) 

	

    SQLITE_INTERNAL (2)
    SQLITE_INTERRUPT (9)
    SQLITE_IOERR (10)
    SQLITE_LOCKED (6)
    SQLITE_MISMATCH (20)
    SQLITE_MISUSE (21)
    SQLITE_NOLFS (22)
    SQLITE_NOMEM (7)
    SQLITE_NOTADB (26)
    SQLITE_NOTFOUND (12)
    SQLITE_NOTICE (27) 

	

    SQLITE_OK (0)
    SQLITE_PERM (3)
    SQLITE_PROTOCOL (15)
    SQLITE_RANGE (25)
    SQLITE_READONLY (8)
    SQLITE_ROW (100)
    SQLITE_SCHEMA (17)
    SQLITE_TOOBIG (18)
    SQLITE_WARNING (28) """
    
raw_extended_result_codes = """
    SQLITE_ABORT_ROLLBACK (516)
    SQLITE_BUSY_RECOVERY (261)
    SQLITE_BUSY_SNAPSHOT (517)
    SQLITE_CANTOPEN_CONVPATH (1038)
    SQLITE_CANTOPEN_FULLPATH (782)
    SQLITE_CANTOPEN_ISDIR (526)
    SQLITE_CANTOPEN_NOTEMPDIR (270)
    SQLITE_CONSTRAINT_CHECK (275)
    SQLITE_CONSTRAINT_COMMITHOOK (531)
    SQLITE_CONSTRAINT_FOREIGNKEY (787)
    SQLITE_CONSTRAINT_FUNCTION (1043)
    SQLITE_CONSTRAINT_NOTNULL (1299)
    SQLITE_CONSTRAINT_PRIMARYKEY (1555)
    SQLITE_CONSTRAINT_ROWID (2579)
    SQLITE_CONSTRAINT_TRIGGER (1811)
    SQLITE_CONSTRAINT_UNIQUE (2067)
    SQLITE_CONSTRAINT_VTAB (2323)
    SQLITE_CORRUPT_VTAB (267)
    SQLITE_IOERR_ACCESS (3338)
    SQLITE_IOERR_BLOCKED (2826)
    SQLITE_IOERR_CHECKRESERVEDLOCK (3594)
    SQLITE_IOERR_CLOSE (4106)
    SQLITE_IOERR_CONVPATH (6666)
    SQLITE_IOERR_DELETE (2570)
    SQLITE_IOERR_DELETE_NOENT (5898)
    SQLITE_IOERR_DIR_CLOSE (4362) 

	

    SQLITE_IOERR_DIR_FSYNC (1290)
    SQLITE_IOERR_FSTAT (1802)
    SQLITE_IOERR_FSYNC (1034)
    SQLITE_IOERR_GETTEMPPATH (6410)
    SQLITE_IOERR_LOCK (3850)
    SQLITE_IOERR_MMAP (6154)
    SQLITE_IOERR_NOMEM (3082)
    SQLITE_IOERR_RDLOCK (2314)
    SQLITE_IOERR_READ (266)
    SQLITE_IOERR_SEEK (5642)
    SQLITE_IOERR_SHMLOCK (5130)
    SQLITE_IOERR_SHMMAP (5386)
    SQLITE_IOERR_SHMOPEN (4618)
    SQLITE_IOERR_SHMSIZE (4874)
    SQLITE_IOERR_SHORT_READ (522)
    SQLITE_IOERR_TRUNCATE (1546)
    SQLITE_IOERR_UNLOCK (2058)
    SQLITE_IOERR_WRITE (778)
    SQLITE_LOCKED_SHAREDCACHE (262)
    SQLITE_NOTICE_RECOVER_ROLLBACK (539)
    SQLITE_NOTICE_RECOVER_WAL (283)
    SQLITE_READONLY_CANTLOCK (520)
    SQLITE_READONLY_DBMOVED (1032)
    SQLITE_READONLY_RECOVERY (264)
    SQLITE_READONLY_ROLLBACK (776)
    SQLITE_WARNING_AUTOINDEX (284) """


def class_name(error_name):
	"""Es. input: SQLITE_ABORT"""
	ret = ""
	
	for word in error_name.split("_"):
		ret += word[0] + word[1:].lower()
		
	return ret


def exceptions_definition_from_raw_list(l):
	"""
	Crea la definizione delle eccezioni passando come input la lista degli errori 
	contenuta in questa pagina: https://sqlite.org/rescode.html
	
	Es:
	
    SQLITE_ABORT (4)
    SQLITE_AUTH (23)
    SQLITE_BUSY (5)
    SQLITE_CANTOPEN (14)
    SQLITE_CONSTRAINT (19)
    SQLITE_CORRUPT (11)
    SQLITE_DONE (101)
    SQLITE_EMPTY (16)
    SQLITE_ERROR (1)
    SQLITE_FORMAT (24)
    SQLITE_FULL (13) 
    
    ...
	"""
	
	ret = ""
	
	for row in l.split("\n"):
		if "SQLITE" in row:
			const_name = row.strip().split(" ")[0]
			
			if not (const_name in not_error_codes):
				ret += "class %s: public std::runtime_error\n{\n\tpublic:\n\t\t%s(const std::string& msg): std::runtime_error(msg){}\n};\n\n" % (class_name(const_name), class_name(const_name))
			
	return ret


def switch_case_from_raw_list_0(l, namespace_, exception_str):
	"""
	Crea i case di uno switch come
	
	switch(errorCode)
	{
		case SQLITE_ABORT:
			throw exceptions::primary::SqliteAbort(sqlite3_errmsg(db));
		
		...
	}
	
	per sollevare l'eccezione giusta a seconda del codice di errore.
	
	Prende in input la lista degli errori contenuta in questa pagina: 
	https://sqlite.org/rescode.html
	
	Es:
	
    SQLITE_ABORT (4)
    SQLITE_AUTH (23)
    SQLITE_BUSY (5)
    SQLITE_CANTOPEN (14)
    SQLITE_CONSTRAINT (19)
    SQLITE_CORRUPT (11)
    SQLITE_DONE (101)
    SQLITE_EMPTY (16)
    SQLITE_ERROR (1)
    SQLITE_FORMAT (24)
    SQLITE_FULL (13) 
    
    ...
    
    Il nome dell'eccezione è autogenerato, ma deve essere specificato il namespace
    nel quale è contenuta.
    
    In exception_str, effettua queste sostituzioni:
	
		* ERRORCODE -> Nome della costante per il codice di errore
    """

	ret = ""
	
	for row in l.split("\n"):
		if "SQLITE" in row:
			const_name = row.strip().split(" ")[0]
			if not (const_name in not_error_codes):
				ret += "case %s:\n\tthrow %s::%s(%s);\n\n" % (const_name, namespace_,  class_name(const_name), exception_str.replace("ERRORCODE", const_name))

	return ret


def switch_case_from_raw_list_1(l, namespace_, db_var_name):
	"""
    Come switch_case_from_raw_list_0(). Usa sqlite3_errmsg() per ricavare il messaggio delle eccezioni.
	"""
	
	return switch_case_from_raw_list_0(l, namespace_, "sqlite3_errmsg(%s)" % db_var_name)


def switch_case_from_raw_list_2(l, namespace_):
	"""Come switch_case_from_raw_list_0(). Utilizza sqlite3_errstr() per ricavare il messaggio di errore."""
	return switch_case_from_raw_list_0(l, namespace_, "sqlite3_errstr(ERRORCODE)")
	
	



