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

// XXX Eccezioni brutte, mettere sql dopo errore

int
sqlite3pp::throwException(sqlite3* db, string sql)
{
	return throwException(sqlite3_extended_errcode(db), db, sql);
}


int
sqlite3pp::throwException(int errorCode, string sql)
{
	switch(errorCode)
	{
		case SQLITE_ABORT:
			throw exceptions::primary::SqliteAbort(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_ABORT));

		case SQLITE_AUTH:
			throw exceptions::primary::SqliteAuth(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_AUTH));

		case SQLITE_BUSY:
			throw exceptions::primary::SqliteBusy(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_BUSY));

		case SQLITE_CANTOPEN:
			throw exceptions::primary::SqliteCantopen(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CANTOPEN));

		case SQLITE_CONSTRAINT:
			throw exceptions::primary::SqliteConstraint(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT));

		case SQLITE_CORRUPT:
			throw exceptions::primary::SqliteCorrupt(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CORRUPT));

		case SQLITE_EMPTY:
			throw exceptions::primary::SqliteEmpty(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_EMPTY));

		case SQLITE_ERROR:
			throw exceptions::primary::SqliteError(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_ERROR));

		case SQLITE_FORMAT:
			throw exceptions::primary::SqliteFormat(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_FORMAT));

		case SQLITE_FULL:
			throw exceptions::primary::SqliteFull(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_FULL));

		case SQLITE_INTERNAL:
			throw exceptions::primary::SqliteInternal(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_INTERNAL));

		case SQLITE_INTERRUPT:
			throw exceptions::primary::SqliteInterrupt(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_INTERRUPT));

		case SQLITE_IOERR:
			throw exceptions::primary::SqliteIoerr(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR));

		case SQLITE_LOCKED:
			throw exceptions::primary::SqliteLocked(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_LOCKED));

		case SQLITE_MISMATCH:
			throw exceptions::primary::SqliteMismatch(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_MISMATCH));

		case SQLITE_MISUSE:
			throw exceptions::primary::SqliteMisuse(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_MISUSE));

		case SQLITE_NOLFS:
			throw exceptions::primary::SqliteNolfs(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_NOLFS));

		case SQLITE_NOMEM:
			throw exceptions::primary::SqliteNomem(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_NOMEM));

		case SQLITE_NOTADB:
			throw exceptions::primary::SqliteNotadb(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_NOTADB));

		case SQLITE_NOTFOUND:
			throw exceptions::primary::SqliteNotfound(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_NOTFOUND));

		case SQLITE_NOTICE:
			throw exceptions::primary::SqliteNotice(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_NOTICE));

		case SQLITE_PERM:
			throw exceptions::primary::SqlitePerm(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_PERM));

		case SQLITE_PROTOCOL:
			throw exceptions::primary::SqliteProtocol(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_PROTOCOL));

		case SQLITE_RANGE:
			throw exceptions::primary::SqliteRange(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_RANGE));

		case SQLITE_READONLY:
			throw exceptions::primary::SqliteReadonly(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_READONLY));

		case SQLITE_SCHEMA:
			throw exceptions::primary::SqliteSchema(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_SCHEMA));

		case SQLITE_TOOBIG:
			throw exceptions::primary::SqliteToobig(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_TOOBIG));

		case SQLITE_WARNING:
			throw exceptions::primary::SqliteWarning(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_WARNING));

		case SQLITE_ABORT_ROLLBACK:
			throw exceptions::extended::SqliteAbortRollback(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_ABORT_ROLLBACK));

		case SQLITE_BUSY_RECOVERY:
			throw exceptions::extended::SqliteBusyRecovery(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_BUSY_RECOVERY));

		case SQLITE_BUSY_SNAPSHOT:
			throw exceptions::extended::SqliteBusySnapshot(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_BUSY_SNAPSHOT));

		case SQLITE_CANTOPEN_CONVPATH:
			throw exceptions::extended::SqliteCantopenConvpath(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CANTOPEN_CONVPATH));

		case SQLITE_CANTOPEN_FULLPATH:
			throw exceptions::extended::SqliteCantopenFullpath(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CANTOPEN_FULLPATH));

		case SQLITE_CANTOPEN_ISDIR:
			throw exceptions::extended::SqliteCantopenIsdir(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CANTOPEN_ISDIR));

		case SQLITE_CANTOPEN_NOTEMPDIR:
			throw exceptions::extended::SqliteCantopenNotempdir(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CANTOPEN_NOTEMPDIR));

		case SQLITE_CONSTRAINT_CHECK:
			throw exceptions::extended::SqliteConstraintCheck(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT_CHECK));

		case SQLITE_CONSTRAINT_COMMITHOOK:
			throw exceptions::extended::SqliteConstraintCommithook(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT_COMMITHOOK));

		case SQLITE_CONSTRAINT_FOREIGNKEY:
			throw exceptions::extended::SqliteConstraintForeignkey(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT_FOREIGNKEY));

		case SQLITE_CONSTRAINT_FUNCTION:
			throw exceptions::extended::SqliteConstraintFunction(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT_FUNCTION));

		case SQLITE_CONSTRAINT_NOTNULL:
			throw exceptions::extended::SqliteConstraintNotnull(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT_NOTNULL));

		case SQLITE_CONSTRAINT_PRIMARYKEY:
			throw exceptions::extended::SqliteConstraintPrimarykey(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT_PRIMARYKEY));

		case SQLITE_CONSTRAINT_ROWID:
			throw exceptions::extended::SqliteConstraintRowid(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT_ROWID));

		case SQLITE_CONSTRAINT_TRIGGER:
			throw exceptions::extended::SqliteConstraintTrigger(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT_TRIGGER));

		case SQLITE_CONSTRAINT_UNIQUE:
			throw exceptions::extended::SqliteConstraintUnique(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT_UNIQUE));

		case SQLITE_CONSTRAINT_VTAB:
			throw exceptions::extended::SqliteConstraintVtab(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CONSTRAINT_VTAB));

		case SQLITE_CORRUPT_VTAB:
			throw exceptions::extended::SqliteCorruptVtab(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_CORRUPT_VTAB));

		case SQLITE_IOERR_ACCESS:
			throw exceptions::extended::SqliteIoerrAccess(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_ACCESS));

		case SQLITE_IOERR_BLOCKED:
			throw exceptions::extended::SqliteIoerrBlocked(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_BLOCKED));

		case SQLITE_IOERR_CHECKRESERVEDLOCK:
			throw exceptions::extended::SqliteIoerrCheckreservedlock(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_CHECKRESERVEDLOCK));

		case SQLITE_IOERR_CLOSE:
			throw exceptions::extended::SqliteIoerrClose(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_CLOSE));

		case SQLITE_IOERR_CONVPATH:
			throw exceptions::extended::SqliteIoerrConvpath(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_CONVPATH));

		case SQLITE_IOERR_DELETE:
			throw exceptions::extended::SqliteIoerrDelete(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_DELETE));

		case SQLITE_IOERR_DELETE_NOENT:
			throw exceptions::extended::SqliteIoerrDeleteNoent(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_DELETE_NOENT));

		case SQLITE_IOERR_DIR_CLOSE:
			throw exceptions::extended::SqliteIoerrDirClose(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_DIR_CLOSE));

		case SQLITE_IOERR_DIR_FSYNC:
			throw exceptions::extended::SqliteIoerrDirFsync(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_DIR_FSYNC));

		case SQLITE_IOERR_FSTAT:
			throw exceptions::extended::SqliteIoerrFstat(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_FSTAT));

		case SQLITE_IOERR_FSYNC:
			throw exceptions::extended::SqliteIoerrFsync(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_FSYNC));

		case SQLITE_IOERR_GETTEMPPATH:
			throw exceptions::extended::SqliteIoerrGettemppath(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_GETTEMPPATH));

		case SQLITE_IOERR_LOCK:
			throw exceptions::extended::SqliteIoerrLock(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_LOCK));

		case SQLITE_IOERR_MMAP:
			throw exceptions::extended::SqliteIoerrMmap(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_MMAP));

		case SQLITE_IOERR_NOMEM:
			throw exceptions::extended::SqliteIoerrNomem(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_NOMEM));

		case SQLITE_IOERR_RDLOCK:
			throw exceptions::extended::SqliteIoerrRdlock(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_RDLOCK));

		case SQLITE_IOERR_READ:
			throw exceptions::extended::SqliteIoerrRead(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_READ));

		case SQLITE_IOERR_SEEK:
			throw exceptions::extended::SqliteIoerrSeek(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_SEEK));

		case SQLITE_IOERR_SHMLOCK:
			throw exceptions::extended::SqliteIoerrShmlock(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_SHMLOCK));

		case SQLITE_IOERR_SHMMAP:
			throw exceptions::extended::SqliteIoerrShmmap(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_SHMMAP));

		case SQLITE_IOERR_SHMOPEN:
			throw exceptions::extended::SqliteIoerrShmopen(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_SHMOPEN));

		case SQLITE_IOERR_SHMSIZE:
			throw exceptions::extended::SqliteIoerrShmsize(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_SHMSIZE));

		case SQLITE_IOERR_SHORT_READ:
			throw exceptions::extended::SqliteIoerrShortRead(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_SHORT_READ));

		case SQLITE_IOERR_TRUNCATE:
			throw exceptions::extended::SqliteIoerrTruncate(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_TRUNCATE));

		case SQLITE_IOERR_UNLOCK:
			throw exceptions::extended::SqliteIoerrUnlock(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_UNLOCK));

		case SQLITE_IOERR_WRITE:
			throw exceptions::extended::SqliteIoerrWrite(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_IOERR_WRITE));

		case SQLITE_LOCKED_SHAREDCACHE:
			throw exceptions::extended::SqliteLockedSharedcache(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_LOCKED_SHAREDCACHE));

		case SQLITE_NOTICE_RECOVER_ROLLBACK:
			throw exceptions::extended::SqliteNoticeRecoverRollback(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_NOTICE_RECOVER_ROLLBACK));

		case SQLITE_NOTICE_RECOVER_WAL:
			throw exceptions::extended::SqliteNoticeRecoverWal(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_NOTICE_RECOVER_WAL));

		case SQLITE_READONLY_CANTLOCK:
			throw exceptions::extended::SqliteReadonlyCantlock(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_READONLY_CANTLOCK));

		case SQLITE_READONLY_DBMOVED:
			throw exceptions::extended::SqliteReadonlyDbmoved(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_READONLY_DBMOVED));

		case SQLITE_READONLY_RECOVERY:
			throw exceptions::extended::SqliteReadonlyRecovery(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_READONLY_RECOVERY));

		case SQLITE_READONLY_ROLLBACK:
			throw exceptions::extended::SqliteReadonlyRollback(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_READONLY_ROLLBACK));

		case SQLITE_WARNING_AUTOINDEX:
			throw exceptions::extended::SqliteWarningAutoindex(((sql != "")? sql + "\n" : "") + sqlite3_errstr(SQLITE_WARNING_AUTOINDEX));

		default:
			return errorCode;
	}
}


int
sqlite3pp::throwException(const int errorCode, sqlite3 *db, string sql)
{
	switch(errorCode)
	{
		case SQLITE_ABORT:
			throw exceptions::primary::SqliteAbort(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_AUTH:
			throw exceptions::primary::SqliteAuth(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_BUSY:
			throw exceptions::primary::SqliteBusy(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CANTOPEN:
			throw exceptions::primary::SqliteCantopen(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT:
			throw exceptions::primary::SqliteConstraint(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CORRUPT:
			throw exceptions::primary::SqliteCorrupt(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_EMPTY:
			throw exceptions::primary::SqliteEmpty(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_ERROR:
			throw exceptions::primary::SqliteError(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_FORMAT:
			throw exceptions::primary::SqliteFormat(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_FULL:
			throw exceptions::primary::SqliteFull(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_INTERNAL:
			throw exceptions::primary::SqliteInternal(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_INTERRUPT:
			throw exceptions::primary::SqliteInterrupt(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR:
			throw exceptions::primary::SqliteIoerr(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_LOCKED:
			throw exceptions::primary::SqliteLocked(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_MISMATCH:
			throw exceptions::primary::SqliteMismatch(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_MISUSE:
			throw exceptions::primary::SqliteMisuse(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_NOLFS:
			throw exceptions::primary::SqliteNolfs(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_NOMEM:
			throw exceptions::primary::SqliteNomem(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_NOTADB:
			throw exceptions::primary::SqliteNotadb(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_NOTFOUND:
			throw exceptions::primary::SqliteNotfound(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_NOTICE:
			throw exceptions::primary::SqliteNotice(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_PERM:
			throw exceptions::primary::SqlitePerm(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_PROTOCOL:
			throw exceptions::primary::SqliteProtocol(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_RANGE:
			throw exceptions::primary::SqliteRange(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_READONLY:
			throw exceptions::primary::SqliteReadonly(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_SCHEMA:
			throw exceptions::primary::SqliteSchema(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_TOOBIG:
			throw exceptions::primary::SqliteToobig(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_WARNING:
			throw exceptions::primary::SqliteWarning(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_ABORT_ROLLBACK:
			throw exceptions::extended::SqliteAbortRollback(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_BUSY_RECOVERY:
			throw exceptions::extended::SqliteBusyRecovery(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_BUSY_SNAPSHOT:
			throw exceptions::extended::SqliteBusySnapshot(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CANTOPEN_CONVPATH:
			throw exceptions::extended::SqliteCantopenConvpath(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CANTOPEN_FULLPATH:
			throw exceptions::extended::SqliteCantopenFullpath(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CANTOPEN_ISDIR:
			throw exceptions::extended::SqliteCantopenIsdir(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CANTOPEN_NOTEMPDIR:
			throw exceptions::extended::SqliteCantopenNotempdir(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_CHECK:
			throw exceptions::extended::SqliteConstraintCheck(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_COMMITHOOK:
			throw exceptions::extended::SqliteConstraintCommithook(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_FOREIGNKEY:
			throw exceptions::extended::SqliteConstraintForeignkey(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_FUNCTION:
			throw exceptions::extended::SqliteConstraintFunction(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_NOTNULL:
			throw exceptions::extended::SqliteConstraintNotnull(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_PRIMARYKEY:
			throw exceptions::extended::SqliteConstraintPrimarykey(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_ROWID:
			throw exceptions::extended::SqliteConstraintRowid(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_TRIGGER:
			throw exceptions::extended::SqliteConstraintTrigger(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_UNIQUE:
			throw exceptions::extended::SqliteConstraintUnique(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_VTAB:
			throw exceptions::extended::SqliteConstraintVtab(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_CORRUPT_VTAB:
			throw exceptions::extended::SqliteCorruptVtab(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_ACCESS:
			throw exceptions::extended::SqliteIoerrAccess(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_BLOCKED:
			throw exceptions::extended::SqliteIoerrBlocked(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_CHECKRESERVEDLOCK:
			throw exceptions::extended::SqliteIoerrCheckreservedlock(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_CLOSE:
			throw exceptions::extended::SqliteIoerrClose(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_CONVPATH:
			throw exceptions::extended::SqliteIoerrConvpath(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_DELETE:
			throw exceptions::extended::SqliteIoerrDelete(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_DELETE_NOENT:
			throw exceptions::extended::SqliteIoerrDeleteNoent(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_DIR_CLOSE:
			throw exceptions::extended::SqliteIoerrDirClose(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_DIR_FSYNC:
			throw exceptions::extended::SqliteIoerrDirFsync(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_FSTAT:
			throw exceptions::extended::SqliteIoerrFstat(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_FSYNC:
			throw exceptions::extended::SqliteIoerrFsync(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_GETTEMPPATH:
			throw exceptions::extended::SqliteIoerrGettemppath(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_LOCK:
			throw exceptions::extended::SqliteIoerrLock(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_MMAP:
			throw exceptions::extended::SqliteIoerrMmap(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_NOMEM:
			throw exceptions::extended::SqliteIoerrNomem(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_RDLOCK:
			throw exceptions::extended::SqliteIoerrRdlock(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_READ:
			throw exceptions::extended::SqliteIoerrRead(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_SEEK:
			throw exceptions::extended::SqliteIoerrSeek(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_SHMLOCK:
			throw exceptions::extended::SqliteIoerrShmlock(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_SHMMAP:
			throw exceptions::extended::SqliteIoerrShmmap(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_SHMOPEN:
			throw exceptions::extended::SqliteIoerrShmopen(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_SHMSIZE:
			throw exceptions::extended::SqliteIoerrShmsize(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_SHORT_READ:
			throw exceptions::extended::SqliteIoerrShortRead(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_TRUNCATE:
			throw exceptions::extended::SqliteIoerrTruncate(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_UNLOCK:
			throw exceptions::extended::SqliteIoerrUnlock(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_IOERR_WRITE:
			throw exceptions::extended::SqliteIoerrWrite(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_LOCKED_SHAREDCACHE:
			throw exceptions::extended::SqliteLockedSharedcache(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_NOTICE_RECOVER_ROLLBACK:
			throw exceptions::extended::SqliteNoticeRecoverRollback(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_NOTICE_RECOVER_WAL:
			throw exceptions::extended::SqliteNoticeRecoverWal(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_READONLY_CANTLOCK:
			throw exceptions::extended::SqliteReadonlyCantlock(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_READONLY_DBMOVED:
			throw exceptions::extended::SqliteReadonlyDbmoved(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_READONLY_RECOVERY:
			throw exceptions::extended::SqliteReadonlyRecovery(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_READONLY_ROLLBACK:
			throw exceptions::extended::SqliteReadonlyRollback(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		case SQLITE_WARNING_AUTOINDEX:
			throw exceptions::extended::SqliteWarningAutoindex(((sql != "")? sql + "\n" : "") + sqlite3_errmsg(db));

		default:
			return errorCode;
	}
}

