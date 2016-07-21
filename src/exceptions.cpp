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


int
sqlite3pp::throwException(sqlite3* db)
{
	return throwException(sqlite3_extended_errcode(db), db);
}


int
sqlite3pp::throwException(int errorCode)
{
	switch(errorCode)
	{
		case SQLITE_ABORT:
			throw exceptions::primary::SqliteAbort(sqlite3_errstr(SQLITE_ABORT));

		case SQLITE_AUTH:
			throw exceptions::primary::SqliteAuth(sqlite3_errstr(SQLITE_AUTH));

		case SQLITE_BUSY:
			throw exceptions::primary::SqliteBusy(sqlite3_errstr(SQLITE_BUSY));

		case SQLITE_CANTOPEN:
			throw exceptions::primary::SqliteCantopen(sqlite3_errstr(SQLITE_CANTOPEN));

		case SQLITE_CONSTRAINT:
			throw exceptions::primary::SqliteConstraint(sqlite3_errstr(SQLITE_CONSTRAINT));

		case SQLITE_CORRUPT:
			throw exceptions::primary::SqliteCorrupt(sqlite3_errstr(SQLITE_CORRUPT));

		case SQLITE_EMPTY:
			throw exceptions::primary::SqliteEmpty(sqlite3_errstr(SQLITE_EMPTY));

		case SQLITE_ERROR:
			throw exceptions::primary::SqliteError(sqlite3_errstr(SQLITE_ERROR));

		case SQLITE_FORMAT:
			throw exceptions::primary::SqliteFormat(sqlite3_errstr(SQLITE_FORMAT));

		case SQLITE_FULL:
			throw exceptions::primary::SqliteFull(sqlite3_errstr(SQLITE_FULL));

		case SQLITE_INTERNAL:
			throw exceptions::primary::SqliteInternal(sqlite3_errstr(SQLITE_INTERNAL));

		case SQLITE_INTERRUPT:
			throw exceptions::primary::SqliteInterrupt(sqlite3_errstr(SQLITE_INTERRUPT));

		case SQLITE_IOERR:
			throw exceptions::primary::SqliteIoerr(sqlite3_errstr(SQLITE_IOERR));

		case SQLITE_LOCKED:
			throw exceptions::primary::SqliteLocked(sqlite3_errstr(SQLITE_LOCKED));

		case SQLITE_MISMATCH:
			throw exceptions::primary::SqliteMismatch(sqlite3_errstr(SQLITE_MISMATCH));

		case SQLITE_MISUSE:
			throw exceptions::primary::SqliteMisuse(sqlite3_errstr(SQLITE_MISUSE));

		case SQLITE_NOLFS:
			throw exceptions::primary::SqliteNolfs(sqlite3_errstr(SQLITE_NOLFS));

		case SQLITE_NOMEM:
			throw exceptions::primary::SqliteNomem(sqlite3_errstr(SQLITE_NOMEM));

		case SQLITE_NOTADB:
			throw exceptions::primary::SqliteNotadb(sqlite3_errstr(SQLITE_NOTADB));

		case SQLITE_NOTFOUND:
			throw exceptions::primary::SqliteNotfound(sqlite3_errstr(SQLITE_NOTFOUND));

		case SQLITE_NOTICE:
			throw exceptions::primary::SqliteNotice(sqlite3_errstr(SQLITE_NOTICE));

		case SQLITE_PERM:
			throw exceptions::primary::SqlitePerm(sqlite3_errstr(SQLITE_PERM));

		case SQLITE_PROTOCOL:
			throw exceptions::primary::SqliteProtocol(sqlite3_errstr(SQLITE_PROTOCOL));

		case SQLITE_RANGE:
			throw exceptions::primary::SqliteRange(sqlite3_errstr(SQLITE_RANGE));

		case SQLITE_READONLY:
			throw exceptions::primary::SqliteReadonly(sqlite3_errstr(SQLITE_READONLY));

		case SQLITE_SCHEMA:
			throw exceptions::primary::SqliteSchema(sqlite3_errstr(SQLITE_SCHEMA));

		case SQLITE_TOOBIG:
			throw exceptions::primary::SqliteToobig(sqlite3_errstr(SQLITE_TOOBIG));

		case SQLITE_WARNING:
			throw exceptions::primary::SqliteWarning(sqlite3_errstr(SQLITE_WARNING));

		case SQLITE_ABORT_ROLLBACK:
			throw exceptions::extended::SqliteAbortRollback(sqlite3_errstr(SQLITE_ABORT_ROLLBACK));

		case SQLITE_BUSY_RECOVERY:
			throw exceptions::extended::SqliteBusyRecovery(sqlite3_errstr(SQLITE_BUSY_RECOVERY));

		case SQLITE_BUSY_SNAPSHOT:
			throw exceptions::extended::SqliteBusySnapshot(sqlite3_errstr(SQLITE_BUSY_SNAPSHOT));

		case SQLITE_CANTOPEN_CONVPATH:
			throw exceptions::extended::SqliteCantopenConvpath(sqlite3_errstr(SQLITE_CANTOPEN_CONVPATH));

		case SQLITE_CANTOPEN_FULLPATH:
			throw exceptions::extended::SqliteCantopenFullpath(sqlite3_errstr(SQLITE_CANTOPEN_FULLPATH));

		case SQLITE_CANTOPEN_ISDIR:
			throw exceptions::extended::SqliteCantopenIsdir(sqlite3_errstr(SQLITE_CANTOPEN_ISDIR));

		case SQLITE_CANTOPEN_NOTEMPDIR:
			throw exceptions::extended::SqliteCantopenNotempdir(sqlite3_errstr(SQLITE_CANTOPEN_NOTEMPDIR));

		case SQLITE_CONSTRAINT_CHECK:
			throw exceptions::extended::SqliteConstraintCheck(sqlite3_errstr(SQLITE_CONSTRAINT_CHECK));

		case SQLITE_CONSTRAINT_COMMITHOOK:
			throw exceptions::extended::SqliteConstraintCommithook(sqlite3_errstr(SQLITE_CONSTRAINT_COMMITHOOK));

		case SQLITE_CONSTRAINT_FOREIGNKEY:
			throw exceptions::extended::SqliteConstraintForeignkey(sqlite3_errstr(SQLITE_CONSTRAINT_FOREIGNKEY));

		case SQLITE_CONSTRAINT_FUNCTION:
			throw exceptions::extended::SqliteConstraintFunction(sqlite3_errstr(SQLITE_CONSTRAINT_FUNCTION));

		case SQLITE_CONSTRAINT_NOTNULL:
			throw exceptions::extended::SqliteConstraintNotnull(sqlite3_errstr(SQLITE_CONSTRAINT_NOTNULL));

		case SQLITE_CONSTRAINT_PRIMARYKEY:
			throw exceptions::extended::SqliteConstraintPrimarykey(sqlite3_errstr(SQLITE_CONSTRAINT_PRIMARYKEY));

		case SQLITE_CONSTRAINT_ROWID:
			throw exceptions::extended::SqliteConstraintRowid(sqlite3_errstr(SQLITE_CONSTRAINT_ROWID));

		case SQLITE_CONSTRAINT_TRIGGER:
			throw exceptions::extended::SqliteConstraintTrigger(sqlite3_errstr(SQLITE_CONSTRAINT_TRIGGER));

		case SQLITE_CONSTRAINT_UNIQUE:
			throw exceptions::extended::SqliteConstraintUnique(sqlite3_errstr(SQLITE_CONSTRAINT_UNIQUE));

		case SQLITE_CONSTRAINT_VTAB:
			throw exceptions::extended::SqliteConstraintVtab(sqlite3_errstr(SQLITE_CONSTRAINT_VTAB));

		case SQLITE_CORRUPT_VTAB:
			throw exceptions::extended::SqliteCorruptVtab(sqlite3_errstr(SQLITE_CORRUPT_VTAB));

		case SQLITE_IOERR_ACCESS:
			throw exceptions::extended::SqliteIoerrAccess(sqlite3_errstr(SQLITE_IOERR_ACCESS));

		case SQLITE_IOERR_BLOCKED:
			throw exceptions::extended::SqliteIoerrBlocked(sqlite3_errstr(SQLITE_IOERR_BLOCKED));

		case SQLITE_IOERR_CHECKRESERVEDLOCK:
			throw exceptions::extended::SqliteIoerrCheckreservedlock(sqlite3_errstr(SQLITE_IOERR_CHECKRESERVEDLOCK));

		case SQLITE_IOERR_CLOSE:
			throw exceptions::extended::SqliteIoerrClose(sqlite3_errstr(SQLITE_IOERR_CLOSE));

		case SQLITE_IOERR_CONVPATH:
			throw exceptions::extended::SqliteIoerrConvpath(sqlite3_errstr(SQLITE_IOERR_CONVPATH));

		case SQLITE_IOERR_DELETE:
			throw exceptions::extended::SqliteIoerrDelete(sqlite3_errstr(SQLITE_IOERR_DELETE));

		case SQLITE_IOERR_DELETE_NOENT:
			throw exceptions::extended::SqliteIoerrDeleteNoent(sqlite3_errstr(SQLITE_IOERR_DELETE_NOENT));

		case SQLITE_IOERR_DIR_CLOSE:
			throw exceptions::extended::SqliteIoerrDirClose(sqlite3_errstr(SQLITE_IOERR_DIR_CLOSE));

		case SQLITE_IOERR_DIR_FSYNC:
			throw exceptions::extended::SqliteIoerrDirFsync(sqlite3_errstr(SQLITE_IOERR_DIR_FSYNC));

		case SQLITE_IOERR_FSTAT:
			throw exceptions::extended::SqliteIoerrFstat(sqlite3_errstr(SQLITE_IOERR_FSTAT));

		case SQLITE_IOERR_FSYNC:
			throw exceptions::extended::SqliteIoerrFsync(sqlite3_errstr(SQLITE_IOERR_FSYNC));

		case SQLITE_IOERR_GETTEMPPATH:
			throw exceptions::extended::SqliteIoerrGettemppath(sqlite3_errstr(SQLITE_IOERR_GETTEMPPATH));

		case SQLITE_IOERR_LOCK:
			throw exceptions::extended::SqliteIoerrLock(sqlite3_errstr(SQLITE_IOERR_LOCK));

		case SQLITE_IOERR_MMAP:
			throw exceptions::extended::SqliteIoerrMmap(sqlite3_errstr(SQLITE_IOERR_MMAP));

		case SQLITE_IOERR_NOMEM:
			throw exceptions::extended::SqliteIoerrNomem(sqlite3_errstr(SQLITE_IOERR_NOMEM));

		case SQLITE_IOERR_RDLOCK:
			throw exceptions::extended::SqliteIoerrRdlock(sqlite3_errstr(SQLITE_IOERR_RDLOCK));

		case SQLITE_IOERR_READ:
			throw exceptions::extended::SqliteIoerrRead(sqlite3_errstr(SQLITE_IOERR_READ));

		case SQLITE_IOERR_SEEK:
			throw exceptions::extended::SqliteIoerrSeek(sqlite3_errstr(SQLITE_IOERR_SEEK));

		case SQLITE_IOERR_SHMLOCK:
			throw exceptions::extended::SqliteIoerrShmlock(sqlite3_errstr(SQLITE_IOERR_SHMLOCK));

		case SQLITE_IOERR_SHMMAP:
			throw exceptions::extended::SqliteIoerrShmmap(sqlite3_errstr(SQLITE_IOERR_SHMMAP));

		case SQLITE_IOERR_SHMOPEN:
			throw exceptions::extended::SqliteIoerrShmopen(sqlite3_errstr(SQLITE_IOERR_SHMOPEN));

		case SQLITE_IOERR_SHMSIZE:
			throw exceptions::extended::SqliteIoerrShmsize(sqlite3_errstr(SQLITE_IOERR_SHMSIZE));

		case SQLITE_IOERR_SHORT_READ:
			throw exceptions::extended::SqliteIoerrShortRead(sqlite3_errstr(SQLITE_IOERR_SHORT_READ));

		case SQLITE_IOERR_TRUNCATE:
			throw exceptions::extended::SqliteIoerrTruncate(sqlite3_errstr(SQLITE_IOERR_TRUNCATE));

		case SQLITE_IOERR_UNLOCK:
			throw exceptions::extended::SqliteIoerrUnlock(sqlite3_errstr(SQLITE_IOERR_UNLOCK));

		case SQLITE_IOERR_WRITE:
			throw exceptions::extended::SqliteIoerrWrite(sqlite3_errstr(SQLITE_IOERR_WRITE));

		case SQLITE_LOCKED_SHAREDCACHE:
			throw exceptions::extended::SqliteLockedSharedcache(sqlite3_errstr(SQLITE_LOCKED_SHAREDCACHE));

		case SQLITE_NOTICE_RECOVER_ROLLBACK:
			throw exceptions::extended::SqliteNoticeRecoverRollback(sqlite3_errstr(SQLITE_NOTICE_RECOVER_ROLLBACK));

		case SQLITE_NOTICE_RECOVER_WAL:
			throw exceptions::extended::SqliteNoticeRecoverWal(sqlite3_errstr(SQLITE_NOTICE_RECOVER_WAL));

		case SQLITE_READONLY_CANTLOCK:
			throw exceptions::extended::SqliteReadonlyCantlock(sqlite3_errstr(SQLITE_READONLY_CANTLOCK));

		case SQLITE_READONLY_DBMOVED:
			throw exceptions::extended::SqliteReadonlyDbmoved(sqlite3_errstr(SQLITE_READONLY_DBMOVED));

		case SQLITE_READONLY_RECOVERY:
			throw exceptions::extended::SqliteReadonlyRecovery(sqlite3_errstr(SQLITE_READONLY_RECOVERY));

		case SQLITE_READONLY_ROLLBACK:
			throw exceptions::extended::SqliteReadonlyRollback(sqlite3_errstr(SQLITE_READONLY_ROLLBACK));

		case SQLITE_WARNING_AUTOINDEX:
			throw exceptions::extended::SqliteWarningAutoindex(sqlite3_errstr(SQLITE_WARNING_AUTOINDEX));

		default:
			return errorCode;
	}
}


int
sqlite3pp::throwException(const int errorCode, sqlite3 *db)
{
	switch(errorCode)
	{
		case SQLITE_ABORT:
			throw exceptions::primary::SqliteAbort(sqlite3_errmsg(db));

		case SQLITE_AUTH:
			throw exceptions::primary::SqliteAuth(sqlite3_errmsg(db));

		case SQLITE_BUSY:
			throw exceptions::primary::SqliteBusy(sqlite3_errmsg(db));

		case SQLITE_CANTOPEN:
			throw exceptions::primary::SqliteCantopen(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT:
			throw exceptions::primary::SqliteConstraint(sqlite3_errmsg(db));

		case SQLITE_CORRUPT:
			throw exceptions::primary::SqliteCorrupt(sqlite3_errmsg(db));

		case SQLITE_EMPTY:
			throw exceptions::primary::SqliteEmpty(sqlite3_errmsg(db));

		case SQLITE_ERROR:
			throw exceptions::primary::SqliteError(sqlite3_errmsg(db));

		case SQLITE_FORMAT:
			throw exceptions::primary::SqliteFormat(sqlite3_errmsg(db));

		case SQLITE_FULL:
			throw exceptions::primary::SqliteFull(sqlite3_errmsg(db));

		case SQLITE_INTERNAL:
			throw exceptions::primary::SqliteInternal(sqlite3_errmsg(db));

		case SQLITE_INTERRUPT:
			throw exceptions::primary::SqliteInterrupt(sqlite3_errmsg(db));

		case SQLITE_IOERR:
			throw exceptions::primary::SqliteIoerr(sqlite3_errmsg(db));

		case SQLITE_LOCKED:
			throw exceptions::primary::SqliteLocked(sqlite3_errmsg(db));

		case SQLITE_MISMATCH:
			throw exceptions::primary::SqliteMismatch(sqlite3_errmsg(db));

		case SQLITE_MISUSE:
			throw exceptions::primary::SqliteMisuse(sqlite3_errmsg(db));

		case SQLITE_NOLFS:
			throw exceptions::primary::SqliteNolfs(sqlite3_errmsg(db));

		case SQLITE_NOMEM:
			throw exceptions::primary::SqliteNomem(sqlite3_errmsg(db));

		case SQLITE_NOTADB:
			throw exceptions::primary::SqliteNotadb(sqlite3_errmsg(db));

		case SQLITE_NOTFOUND:
			throw exceptions::primary::SqliteNotfound(sqlite3_errmsg(db));

		case SQLITE_NOTICE:
			throw exceptions::primary::SqliteNotice(sqlite3_errmsg(db));

		case SQLITE_PERM:
			throw exceptions::primary::SqlitePerm(sqlite3_errmsg(db));

		case SQLITE_PROTOCOL:
			throw exceptions::primary::SqliteProtocol(sqlite3_errmsg(db));

		case SQLITE_RANGE:
			throw exceptions::primary::SqliteRange(sqlite3_errmsg(db));

		case SQLITE_READONLY:
			throw exceptions::primary::SqliteReadonly(sqlite3_errmsg(db));

		case SQLITE_SCHEMA:
			throw exceptions::primary::SqliteSchema(sqlite3_errmsg(db));

		case SQLITE_TOOBIG:
			throw exceptions::primary::SqliteToobig(sqlite3_errmsg(db));

		case SQLITE_WARNING:
			throw exceptions::primary::SqliteWarning(sqlite3_errmsg(db));

		case SQLITE_ABORT_ROLLBACK:
			throw exceptions::extended::SqliteAbortRollback(sqlite3_errmsg(db));

		case SQLITE_BUSY_RECOVERY:
			throw exceptions::extended::SqliteBusyRecovery(sqlite3_errmsg(db));

		case SQLITE_BUSY_SNAPSHOT:
			throw exceptions::extended::SqliteBusySnapshot(sqlite3_errmsg(db));

		case SQLITE_CANTOPEN_CONVPATH:
			throw exceptions::extended::SqliteCantopenConvpath(sqlite3_errmsg(db));

		case SQLITE_CANTOPEN_FULLPATH:
			throw exceptions::extended::SqliteCantopenFullpath(sqlite3_errmsg(db));

		case SQLITE_CANTOPEN_ISDIR:
			throw exceptions::extended::SqliteCantopenIsdir(sqlite3_errmsg(db));

		case SQLITE_CANTOPEN_NOTEMPDIR:
			throw exceptions::extended::SqliteCantopenNotempdir(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_CHECK:
			throw exceptions::extended::SqliteConstraintCheck(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_COMMITHOOK:
			throw exceptions::extended::SqliteConstraintCommithook(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_FOREIGNKEY:
			throw exceptions::extended::SqliteConstraintForeignkey(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_FUNCTION:
			throw exceptions::extended::SqliteConstraintFunction(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_NOTNULL:
			throw exceptions::extended::SqliteConstraintNotnull(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_PRIMARYKEY:
			throw exceptions::extended::SqliteConstraintPrimarykey(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_ROWID:
			throw exceptions::extended::SqliteConstraintRowid(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_TRIGGER:
			throw exceptions::extended::SqliteConstraintTrigger(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_UNIQUE:
			throw exceptions::extended::SqliteConstraintUnique(sqlite3_errmsg(db));

		case SQLITE_CONSTRAINT_VTAB:
			throw exceptions::extended::SqliteConstraintVtab(sqlite3_errmsg(db));

		case SQLITE_CORRUPT_VTAB:
			throw exceptions::extended::SqliteCorruptVtab(sqlite3_errmsg(db));

		case SQLITE_IOERR_ACCESS:
			throw exceptions::extended::SqliteIoerrAccess(sqlite3_errmsg(db));

		case SQLITE_IOERR_BLOCKED:
			throw exceptions::extended::SqliteIoerrBlocked(sqlite3_errmsg(db));

		case SQLITE_IOERR_CHECKRESERVEDLOCK:
			throw exceptions::extended::SqliteIoerrCheckreservedlock(sqlite3_errmsg(db));

		case SQLITE_IOERR_CLOSE:
			throw exceptions::extended::SqliteIoerrClose(sqlite3_errmsg(db));

		case SQLITE_IOERR_CONVPATH:
			throw exceptions::extended::SqliteIoerrConvpath(sqlite3_errmsg(db));

		case SQLITE_IOERR_DELETE:
			throw exceptions::extended::SqliteIoerrDelete(sqlite3_errmsg(db));

		case SQLITE_IOERR_DELETE_NOENT:
			throw exceptions::extended::SqliteIoerrDeleteNoent(sqlite3_errmsg(db));

		case SQLITE_IOERR_DIR_CLOSE:
			throw exceptions::extended::SqliteIoerrDirClose(sqlite3_errmsg(db));

		case SQLITE_IOERR_DIR_FSYNC:
			throw exceptions::extended::SqliteIoerrDirFsync(sqlite3_errmsg(db));

		case SQLITE_IOERR_FSTAT:
			throw exceptions::extended::SqliteIoerrFstat(sqlite3_errmsg(db));

		case SQLITE_IOERR_FSYNC:
			throw exceptions::extended::SqliteIoerrFsync(sqlite3_errmsg(db));

		case SQLITE_IOERR_GETTEMPPATH:
			throw exceptions::extended::SqliteIoerrGettemppath(sqlite3_errmsg(db));

		case SQLITE_IOERR_LOCK:
			throw exceptions::extended::SqliteIoerrLock(sqlite3_errmsg(db));

		case SQLITE_IOERR_MMAP:
			throw exceptions::extended::SqliteIoerrMmap(sqlite3_errmsg(db));

		case SQLITE_IOERR_NOMEM:
			throw exceptions::extended::SqliteIoerrNomem(sqlite3_errmsg(db));

		case SQLITE_IOERR_RDLOCK:
			throw exceptions::extended::SqliteIoerrRdlock(sqlite3_errmsg(db));

		case SQLITE_IOERR_READ:
			throw exceptions::extended::SqliteIoerrRead(sqlite3_errmsg(db));

		case SQLITE_IOERR_SEEK:
			throw exceptions::extended::SqliteIoerrSeek(sqlite3_errmsg(db));

		case SQLITE_IOERR_SHMLOCK:
			throw exceptions::extended::SqliteIoerrShmlock(sqlite3_errmsg(db));

		case SQLITE_IOERR_SHMMAP:
			throw exceptions::extended::SqliteIoerrShmmap(sqlite3_errmsg(db));

		case SQLITE_IOERR_SHMOPEN:
			throw exceptions::extended::SqliteIoerrShmopen(sqlite3_errmsg(db));

		case SQLITE_IOERR_SHMSIZE:
			throw exceptions::extended::SqliteIoerrShmsize(sqlite3_errmsg(db));

		case SQLITE_IOERR_SHORT_READ:
			throw exceptions::extended::SqliteIoerrShortRead(sqlite3_errmsg(db));

		case SQLITE_IOERR_TRUNCATE:
			throw exceptions::extended::SqliteIoerrTruncate(sqlite3_errmsg(db));

		case SQLITE_IOERR_UNLOCK:
			throw exceptions::extended::SqliteIoerrUnlock(sqlite3_errmsg(db));

		case SQLITE_IOERR_WRITE:
			throw exceptions::extended::SqliteIoerrWrite(sqlite3_errmsg(db));

		case SQLITE_LOCKED_SHAREDCACHE:
			throw exceptions::extended::SqliteLockedSharedcache(sqlite3_errmsg(db));

		case SQLITE_NOTICE_RECOVER_ROLLBACK:
			throw exceptions::extended::SqliteNoticeRecoverRollback(sqlite3_errmsg(db));

		case SQLITE_NOTICE_RECOVER_WAL:
			throw exceptions::extended::SqliteNoticeRecoverWal(sqlite3_errmsg(db));

		case SQLITE_READONLY_CANTLOCK:
			throw exceptions::extended::SqliteReadonlyCantlock(sqlite3_errmsg(db));

		case SQLITE_READONLY_DBMOVED:
			throw exceptions::extended::SqliteReadonlyDbmoved(sqlite3_errmsg(db));

		case SQLITE_READONLY_RECOVERY:
			throw exceptions::extended::SqliteReadonlyRecovery(sqlite3_errmsg(db));

		case SQLITE_READONLY_ROLLBACK:
			throw exceptions::extended::SqliteReadonlyRollback(sqlite3_errmsg(db));

		case SQLITE_WARNING_AUTOINDEX:
			throw exceptions::extended::SqliteWarningAutoindex(sqlite3_errmsg(db));

		default:
			return errorCode;
	}
}

