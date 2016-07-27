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


# ifndef SQLITE3PP_SQLITE3PP_HPP
# define SQLITE3PP_SQLITE3PP_HPP


# include <string>
# include <vector>
# include <stdexcept>
# include <cstring>

# include <sqlite3.h>


// TODO copiare documentazione?


namespace sqlite3pp
{
	namespace exceptions
	{
		namespace primary
		{
			class SqliteAbort: public std::runtime_error
			{
				public:
					SqliteAbort(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteAuth: public std::runtime_error
			{
				public:
					SqliteAuth(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteBusy: public std::runtime_error
			{
				public:
					SqliteBusy(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteCantopen: public std::runtime_error
			{
				public:
					SqliteCantopen(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraint: public std::runtime_error
			{
				public:
					SqliteConstraint(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteCorrupt: public std::runtime_error
			{
				public:
					SqliteCorrupt(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteEmpty: public std::runtime_error
			{
				public:
					SqliteEmpty(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteError: public std::runtime_error
			{
				public:
					SqliteError(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteFormat: public std::runtime_error
			{
				public:
					SqliteFormat(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteFull: public std::runtime_error
			{
				public:
					SqliteFull(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteInternal: public std::runtime_error
			{
				public:
					SqliteInternal(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteInterrupt: public std::runtime_error
			{
				public:
					SqliteInterrupt(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerr: public std::runtime_error
			{
				public:
					SqliteIoerr(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteLocked: public std::runtime_error
			{
				public:
					SqliteLocked(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteMismatch: public std::runtime_error
			{
				public:
					SqliteMismatch(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteMisuse: public std::runtime_error
			{
				public:
					SqliteMisuse(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteNolfs: public std::runtime_error
			{
				public:
					SqliteNolfs(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteNomem: public std::runtime_error
			{
				public:
					SqliteNomem(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteNotadb: public std::runtime_error
			{
				public:
					SqliteNotadb(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteNotfound: public std::runtime_error
			{
				public:
					SqliteNotfound(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteNotice: public std::runtime_error
			{
				public:
					SqliteNotice(const std::string& msg): std::runtime_error(msg){}
			};

			class SqlitePerm: public std::runtime_error
			{
				public:
					SqlitePerm(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteProtocol: public std::runtime_error
			{
				public:
					SqliteProtocol(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteRange: public std::runtime_error
			{
				public:
					SqliteRange(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteReadonly: public std::runtime_error
			{
				public:
					SqliteReadonly(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteSchema: public std::runtime_error
			{
				public:
					SqliteSchema(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteToobig: public std::runtime_error
			{
				public:
					SqliteToobig(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteWarning: public std::runtime_error
			{
				public:
					SqliteWarning(const std::string& msg): std::runtime_error(msg){}
			};
		}
		
		namespace extended
		{
			class SqliteAbortRollback: public std::runtime_error
			{
				public:
					SqliteAbortRollback(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteBusyRecovery: public std::runtime_error
			{
				public:
					SqliteBusyRecovery(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteBusySnapshot: public std::runtime_error
			{
				public:
					SqliteBusySnapshot(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteCantopenConvpath: public std::runtime_error
			{
				public:
					SqliteCantopenConvpath(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteCantopenFullpath: public std::runtime_error
			{
				public:
					SqliteCantopenFullpath(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteCantopenIsdir: public std::runtime_error
			{
				public:
					SqliteCantopenIsdir(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteCantopenNotempdir: public std::runtime_error
			{
				public:
					SqliteCantopenNotempdir(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraintCheck: public std::runtime_error
			{
				public:
					SqliteConstraintCheck(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraintCommithook: public std::runtime_error
			{
				public:
					SqliteConstraintCommithook(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraintForeignkey: public std::runtime_error
			{
				public:
					SqliteConstraintForeignkey(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraintFunction: public std::runtime_error
			{
				public:
					SqliteConstraintFunction(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraintNotnull: public std::runtime_error
			{
				public:
					SqliteConstraintNotnull(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraintPrimarykey: public std::runtime_error
			{
				public:
					SqliteConstraintPrimarykey(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraintRowid: public std::runtime_error
			{
				public:
					SqliteConstraintRowid(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraintTrigger: public std::runtime_error
			{
				public:
					SqliteConstraintTrigger(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraintUnique: public std::runtime_error
			{
				public:
					SqliteConstraintUnique(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteConstraintVtab: public std::runtime_error
			{
				public:
					SqliteConstraintVtab(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteCorruptVtab: public std::runtime_error
			{
				public:
					SqliteCorruptVtab(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrAccess: public std::runtime_error
			{
				public:
					SqliteIoerrAccess(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrBlocked: public std::runtime_error
			{
				public:
					SqliteIoerrBlocked(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrCheckreservedlock: public std::runtime_error
			{
				public:
					SqliteIoerrCheckreservedlock(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrClose: public std::runtime_error
			{
				public:
					SqliteIoerrClose(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrConvpath: public std::runtime_error
			{
				public:
					SqliteIoerrConvpath(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrDelete: public std::runtime_error
			{
				public:
					SqliteIoerrDelete(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrDeleteNoent: public std::runtime_error
			{
				public:
					SqliteIoerrDeleteNoent(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrDirClose: public std::runtime_error
			{
				public:
					SqliteIoerrDirClose(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrDirFsync: public std::runtime_error
			{
				public:
					SqliteIoerrDirFsync(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrFstat: public std::runtime_error
			{
				public:
					SqliteIoerrFstat(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrFsync: public std::runtime_error
			{
				public:
					SqliteIoerrFsync(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrGettemppath: public std::runtime_error
			{
				public:
					SqliteIoerrGettemppath(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrLock: public std::runtime_error
			{
				public:
					SqliteIoerrLock(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrMmap: public std::runtime_error
			{
				public:
					SqliteIoerrMmap(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrNomem: public std::runtime_error
			{
				public:
					SqliteIoerrNomem(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrRdlock: public std::runtime_error
			{
				public:
					SqliteIoerrRdlock(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrRead: public std::runtime_error
			{
				public:
					SqliteIoerrRead(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrSeek: public std::runtime_error
			{
				public:
					SqliteIoerrSeek(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrShmlock: public std::runtime_error
			{
				public:
					SqliteIoerrShmlock(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrShmmap: public std::runtime_error
			{
				public:
					SqliteIoerrShmmap(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrShmopen: public std::runtime_error
			{
				public:
					SqliteIoerrShmopen(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrShmsize: public std::runtime_error
			{
				public:
					SqliteIoerrShmsize(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrShortRead: public std::runtime_error
			{
				public:
					SqliteIoerrShortRead(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrTruncate: public std::runtime_error
			{
				public:
					SqliteIoerrTruncate(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrUnlock: public std::runtime_error
			{
				public:
					SqliteIoerrUnlock(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteIoerrWrite: public std::runtime_error
			{
				public:
					SqliteIoerrWrite(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteLockedSharedcache: public std::runtime_error
			{
				public:
					SqliteLockedSharedcache(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteNoticeRecoverRollback: public std::runtime_error
			{
				public:
					SqliteNoticeRecoverRollback(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteNoticeRecoverWal: public std::runtime_error
			{
				public:
					SqliteNoticeRecoverWal(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteReadonlyCantlock: public std::runtime_error
			{
				public:
					SqliteReadonlyCantlock(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteReadonlyDbmoved: public std::runtime_error
			{
				public:
					SqliteReadonlyDbmoved(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteReadonlyRecovery: public std::runtime_error
			{
				public:
					SqliteReadonlyRecovery(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteReadonlyRollback: public std::runtime_error
			{
				public:
					SqliteReadonlyRollback(const std::string& msg): std::runtime_error(msg){}
			};

			class SqliteWarningAutoindex: public std::runtime_error
			{
				public:
					SqliteWarningAutoindex(const std::string& msg): std::runtime_error(msg){}
			};
		}
	}

	namespace functions
	{
		int sqlite3pp_open(const char *filename, sqlite3 **ppDb);
		int sqlite3pp_close(sqlite3 *db);
		int sqlite3pp_exec(sqlite3 *db, const char *sql, int (*callback)(void*, int, char**, char**), void *firstCallbackArgument, char **errmsg);
		int sqlite3pp_prepare_v2(sqlite3 *db, const char *zSql, int nByte, sqlite3_stmt **ppStmt, const char **pzTail);
		int sqlite3pp_bind_text(sqlite3_stmt* ppStmt, int paramIndex, const char* value, int valueBytes, void(*valueDestructor)(void*));
		int sqlite3pp_bind_int(sqlite3_stmt* ppStmt, int paramIndex, int value);
		int sqlite3pp_bind_int64(sqlite3_stmt* ppStmt, int paramIndex, sqlite3_int64 value);
		int sqlite3pp_step(sqlite3_stmt* ppStmt);
		sqlite3_int64 sqlite3pp_column_int64(sqlite3_stmt* ppStmt, int iCol, sqlite3* db);
		int sqlite3pp_column_int(sqlite3_stmt* ppStmt, int iCol, sqlite3* db);
		const unsigned char *sqlite3pp_column_text(sqlite3_stmt* ppStmt, int iCol, sqlite3* db);
	}


	namespace objects
	{
		using std::string;
		using std::vector;
		

		class DbItem
		{
			public:
							DbItem(sqlite3* db);
				sqlite3*	getParentDb() const;

			private:
				sqlite3		*__db;
		};


		class Table: public DbItem
		{
			public:
									Table(sqlite3 *db, const string tableName);

			string 					getTableName() const;
			vector<sqlite3_int64>	getIdList(string orderBy="", bool ascending=false) const; // Aggiungere nome colonna id?
			bool					isValidId(const sqlite3_int64 id) const;

			virtual void 			remove(const sqlite3_int64 id);


			private:
				const string		__tableName;
		};


		class Row: public DbItem
		{
			public:
				Row(sqlite3 *db, const string tableName, const sqlite3_int64 id);

				string 					getParentTableName() const;
				sqlite3_int64			getId() const;

				// TODO Generalizzare gestione memoria allocata dinamicamente (non è detto che siano tutte stringhe)
				template <typename R> R getColumn(const string columnName, R (*sqlite3ppfunc) (sqlite3_stmt* ppStmt, int iCol, sqlite3* db), bool isString=false) const;
				sqlite3_stmt*			getSelectStatement(const string columnName) const;
				// Sqlite3 bind sul parametro 1 con il valore
				sqlite3_stmt*			getUpdateStatement(const string columnName) const;

			private:
				const string			__tableName;
				const sqlite3_int64		__id;
		};
	}

	using std::string;

	// Utilizza sqlite3_extended_errcode() e sqlite3_errmsg()
	int throwException(sqlite3 *db, string sql="");
	// Usa sqlite3_errstr() per il messaggio di errore
	int throwException(int errorCode, string sql="");
	// Usa sqlite3_errmsg() per il messaggio di errore
	int throwException(int errorCode, sqlite3 *db, string sql="");
}


// I template devono stare nell'header, altrimenti non funzionano quando usata come libreria condivisa


template <typename R> R
sqlite3pp::objects::Row::getColumn(const string columnName, R (*sqlite3ppfunc) (sqlite3_stmt* ppStmt, int iCol, sqlite3* db), bool isString) const
{
	using std::strlen;
	using std::strcpy;
	using std::malloc;

	sqlite3_stmt *ppStmt = getSelectStatement(columnName);
	R ret, tmp;
	
	if (::sqlite3pp::functions::sqlite3pp_step(ppStmt) == SQLITE_ROW)
	{
		tmp = sqlite3ppfunc(ppStmt, 0, getParentDb());
		
		// XXX Fatto a cavolo
		if (isString)
		{
			ret = (R)malloc(strlen((char*)tmp) + 1);
			strcpy((char*)ret, (char*)tmp);
		}
	}
	else
		throw std::runtime_error("Impossibile ottenere la colonna '" + columnName +"'");

	// ATTENZIONE: I puntatori ottenuti con sqlite3ppfunc() non saranno
	// più validi dopo questa funzione, quindi i dati devono essere copiati prima
	sqlite3_finalize(ppStmt);

	return ret;
}

# endif // ifndef SQLITE3PP_SQLITE3PP_HPP
