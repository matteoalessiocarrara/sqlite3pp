/*
 * Copyright 2016 Matteo Alessio Carrara <sw.matteoac@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */
# include <sqlite3.h>

# include "sqlite3pp.hpp"


using namespace sqlite3pp;


int
functions::sqlite3pp_open(const char *filename, sqlite3 **ppDb)
{
	return throwException(sqlite3_open(filename, ppDb), *ppDb);
}


int
functions::sqlite3pp_close(sqlite3 *db)
{
	return throwException(sqlite3_close(db), db);
}


int
functions::sqlite3pp_exec(sqlite3 *db, const char *sql, int (*callback)(void*, int, char**, char**), void *firstCallbackArgument, char **errmsg)
{
	return throwException(sqlite3_exec(db, sql, callback, firstCallbackArgument, errmsg), db, sql);
}


int
functions::sqlite3pp_prepare_v2(sqlite3* db, const char* zSql, int nByte, sqlite3_stmt** ppStmt, const char** pzTail)
{
	return throwException(sqlite3_prepare_v2(db, zSql, nByte, ppStmt, pzTail), db, zSql);
}


int
functions::sqlite3pp_bind_text(sqlite3_stmt* ppStmt, int paramIndex, const char* value, int valueBytes, void(*valueDestructor)(void*))
{
	return throwException(sqlite3_bind_text(ppStmt, paramIndex, value, valueBytes, valueDestructor), sqlite3_sql(ppStmt));
}


int
functions::sqlite3pp_bind_int(sqlite3_stmt* ppStmt, int paramIndex, int value)
{
	return throwException(sqlite3_bind_int(ppStmt, paramIndex, value),sqlite3_sql(ppStmt));
}


int
functions::sqlite3pp_step(sqlite3_stmt* ppStmt)
{
	return throwException(sqlite3_step(ppStmt), sqlite3_sql(ppStmt));
}


int
functions::sqlite3pp_bind_int64(sqlite3_stmt* ppStmt, int paramIndex, sqlite3_int64 value)
{
	return throwException(sqlite3_bind_int64(ppStmt, paramIndex, value), sqlite3_sql(ppStmt));
}


sqlite3_int64
functions::sqlite3pp_column_int64(sqlite3_stmt* ppStmt, int iCol, sqlite3 *db)
{
	sqlite3_int64 r = sqlite3_column_int64(ppStmt, iCol);

	if ((r == 0) && (sqlite3_errcode(db) == SQLITE_NOMEM))
		throwException(SQLITE_NOMEM, sqlite3_sql(ppStmt));

	return r;
}


int
functions::sqlite3pp_column_int(sqlite3_stmt* ppStmt, int iCol, sqlite3 *db)
{
	sqlite3_int64 r = sqlite3_column_int(ppStmt, iCol);

	if ((r == 0) && (sqlite3_errcode(db) == SQLITE_NOMEM))
		throwException(SQLITE_NOMEM, sqlite3_sql(ppStmt));

	return r;
}

const unsigned char*
functions::sqlite3pp_column_text(sqlite3_stmt* ppStmt, int iCol, sqlite3 *db)
{
	const unsigned char *r = sqlite3_column_text(ppStmt, iCol);

	if ((r == NULL) && (sqlite3_errcode(db) == SQLITE_NOMEM))
		throwException(SQLITE_NOMEM, sqlite3_sql(ppStmt));

	return r;
}

