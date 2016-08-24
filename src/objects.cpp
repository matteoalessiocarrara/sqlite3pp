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

# include <string>
# include <vector>
# include <cstring>

# include "../lib/sqlite3/src/sqlite3.h"

# include "sqlite3pp.hpp"


using namespace sqlite3pp::objects;
using std::string;
using std::vector;
using std::strlen;
using std::strcpy;
using std::malloc;


DbItem::DbItem(sqlite3 *db)
{
	__db = db;
}


sqlite3 *
DbItem::getParentDb() const
{
	return __db;
}


Table::Table(sqlite3* db, const string tableName): DbItem(db), __tableName(tableName)
{
}


string
Table::getTableName() const
{
	return __tableName;
}


vector<sqlite3_int64>
Table::getIdList(string orderBy, bool ascending) const
{
	// WARNING Questo non funziona come previsto se la colonna _ROWID_ è stata creata manualmente
	const string			sql = "SELECT _ROWID_ FROM " + getTableName() + 
							((orderBy != "")? " ORDER BY " + orderBy + (ascending? " ASC" : " DESC") : "") + ";";
	sqlite3_stmt			*ppStmt;
	vector<sqlite3_int64>	ret;

	::sqlite3pp::functions::sqlite3pp_prepare_v2(getParentDb(), sql.c_str(), sql.size() + 1, &ppStmt, NULL);

	while(::sqlite3pp::functions::sqlite3pp_step(ppStmt) == SQLITE_ROW)
		ret.insert(ret.end(), ::sqlite3pp::functions::sqlite3pp_column_int64(ppStmt, 0, getParentDb()));

	sqlite3_finalize(ppStmt);

	return ret;
}


bool
Table::isValidId(const sqlite3_int64 id) const
{
	bool valid = false;
	
	for(const int &currId: getIdList())
	{
		if (currId == id)
		{
			valid = true;
			break;
		}
	}

	return valid;
}


void
Table::remove(const sqlite3_int64 id)
{
	// WARNING Questo non funziona come previsto se la colonna _ROWID_ è stata creata manualmente
	const string	sql = "DELETE FROM " + getTableName() + " WHERE _ROWID_ = ?;";
	sqlite3_stmt	*ppStmt;

	::sqlite3pp::functions::sqlite3pp_prepare_v2(getParentDb(), sql.c_str(), sql.size() + 1, &ppStmt, NULL);
	::sqlite3pp::functions::sqlite3pp_bind_int64(ppStmt, 1, id);
	::sqlite3pp::functions::sqlite3pp_step(ppStmt);
	sqlite3_finalize(ppStmt);
}



Row::Row(sqlite3* db, const string tableName, const sqlite3_int64 id): DbItem(db), __tableName(tableName), __id(id)
{
}


string
Row::getParentTableName() const
{
	return __tableName;
}


sqlite3_int64
Row::getId() const
{
	return __id;
}


sqlite3_stmt *
Row::getSelectStatement(const string columnName) const
{
	// WARNING Questo non funziona come previsto se la colonna _ROWID_ è stata creata manualmente
	const string	sql = "SELECT " + columnName + " FROM " + getParentTableName() + " WHERE _ROWID_ = ?;";
	sqlite3_stmt	*ppStmt;

	::sqlite3pp::functions::sqlite3pp_prepare_v2(getParentDb(), sql.c_str(), sql.size() + 1, &ppStmt, NULL);
	::sqlite3pp::functions::sqlite3pp_bind_int64(ppStmt, 1, getId());

	return ppStmt;
}


sqlite3_stmt *
Row::getUpdateStatement(const string columnName) const
{
	// WARNING Questo non funziona come previsto se la colonna _ROWID_ è stata creata manualmente
	const string	sql = 	"UPDATE " + getParentTableName() + " "
							"SET " + columnName + " = ? "
							"WHERE _ROWID_ = ?;";
	sqlite3_stmt	*ppStmt;


	::sqlite3pp::functions::sqlite3pp_prepare_v2(getParentDb(), sql.c_str(), sql.size() + 1, &ppStmt, NULL);
	::sqlite3pp::functions::sqlite3pp_bind_int64(ppStmt, 2, getId());

	return ppStmt;
}


unsigned char *
Row::getColumnString(const string columnName) const
{
	sqlite3_stmt *ppStmt = getSelectStatement(columnName);
	unsigned char *ret, *tmp;

	if (::sqlite3pp::functions::sqlite3pp_step(ppStmt) == SQLITE_ROW)
	{
		tmp = (unsigned char*)::sqlite3pp::functions::sqlite3pp_column_text(ppStmt, 0, getParentDb());
		ret = (unsigned char*)malloc(strlen((char*)tmp) + 1);
		strcpy((char*)ret, (char*)tmp);
	}
	else
		throw std::runtime_error("Impossibile ottenere la colonna '" + columnName +"'");

	sqlite3_finalize(ppStmt);

	return ret;
}
