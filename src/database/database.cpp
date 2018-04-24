#include "database.h"

const db::ItemDTO* db::Database::GetItem(std::string ean) {
  db::ItemDTO *data = NULL;
  int rc = 0;
  rc = sqlite3_bind_text(this->stmt_, 1, ean.c_str(), -1, SQLITE_STATIC);
  rc = sqlite3_step(this->stmt_);
  if (rc == SQLITE_ROW) {
    /* This sure as shit ain't pretty. */
    data = new db::ItemDTO(std::string(reinterpret_cast<const char*>(
                                       sqlite3_column_text(this->stmt_, 0))),
                           std::string(reinterpret_cast<const char*>(
                                       sqlite3_column_text(this->stmt_, 1))),
                           std::string(reinterpret_cast<const char*>(
                                       sqlite3_column_text(this->stmt_, 2))),
                           sqlite3_column_double(this->stmt_, 3));
  }
  /* Caches old SQL execution plan */
  sqlite3_clear_bindings(this->stmt_); 
  sqlite3_reset(this->stmt_);
  return data;
}
