
CREATE TABLE IF NOT EXISTS Books(
    bookName TEXT PRIMARY KEY,
    authorName TEXT,
    bookID INTEGER
)
/*#include <sqlite3.h>
#include <iostream>

void insertBook(sqlite3* db, const Book& book) {
    const char* sql = "INSERT INTO Books (bookID, bookName, authorName) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;

    // Prepare the statement
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << "\n";
        return;
    }

    // Bind values
    sqlite3_bind_int(stmt, 1, book.bookID);
    sqlite3_bind_text(stmt, 2, book.bookName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, book.authorName.c_str(), -1, SQLITE_TRANSIENT);

    // Execute
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Insert failed: " << sqlite3_errmsg(db) << "\n";
    }

    // Clean up
    sqlite3_finalize(stmt);
}
int main() {
    sqlite3* db;
    if (sqlite3_open("mydata.db", &db) != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << "\n";
        return 1;
    }

    Book b1(1, "1984", "George Orwell");
    insertBook(db, b1);

    sqlite3_close(db);
    return 0;
}
*/