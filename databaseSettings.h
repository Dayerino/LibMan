#ifndef SQLTEST
#define SQLTEST
#include <sqlite3.h>
#include "schema.sql"
sqlite3* database;
int rc= sqlite3_open("books.db",&database);
#endif