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
                           sqlite3_column_double(this->stmt_, 3),
                           sqlite3_column_int(this->stmt_, 4));
  }
  rc = sqlite3_column_int(this->stmt_, 4);
  /* Caches old SQL execution plan */
  sqlite3_clear_bindings(this->stmt_); 
  sqlite3_reset(this->stmt_);
  return data;
}

const db::CustomerDTO* db::Database::GetCustomer(std::string id) {
  db::CustomerDTO *data = NULL;
  int rc = 0;
  rc = sqlite3_bind_text(this->stmt_c_, 1, id.c_str(), -1, SQLITE_STATIC);
  rc = sqlite3_step(this->stmt_c_);
  if (rc == SQLITE_ROW) {
    data = new db::CustomerDTO(std::string(reinterpret_cast<const char*>(
                                           sqlite3_column_text(this->stmt_c_, 0))),
                               sqlite3_column_int(this->stmt_c_, 1));
  }
  /* Caches old SQL execution plan, clear it. */
  sqlite3_clear_bindings(this->stmt_c_); 
  sqlite3_reset(this->stmt_c_);
  return data;
}

void db::Database::SetStock(const db::ItemDTO *item, int sold_amount) {
  int rc = 0;
  rc = sqlite3_bind_int(this->stmt_i_,    1, item->stock_ - sold_amount);
  rc = sqlite3_bind_text(this->stmt_i_,   2, item->ean_.c_str(), -1, SQLITE_STATIC);
  rc = sqlite3_step(this->stmt_i_);
  sqlite3_clear_bindings(this->stmt_i_); 
  sqlite3_reset(this->stmt_i_);
}

void db::Database::LogSale(db::SaleDTO *sale) {
  int rc = 0;
  rc = sqlite3_bind_int(this->stmt_s_,    1, sale->worker_);
  rc = sqlite3_bind_text(this->stmt_s_,   2, sale->customer_.c_str(), -1, SQLITE_STATIC);
  rc = sqlite3_bind_double(this->stmt_s_, 3, sale->total_);
  rc = sqlite3_bind_int(this->stmt_s_,    4, sale->discount_);
  rc = sqlite3_bind_text(this->stmt_s_,   5, sale->items_.c_str(), -1, SQLITE_STATIC);
  rc = sqlite3_bind_text(this->stmt_s_,   6, sale->quantity_.c_str(), -1, SQLITE_STATIC);
  rc = sqlite3_step(this->stmt_s_);
  /* Caches old SQL execution plan, clear it. */
  delete sale;
  sqlite3_clear_bindings(this->stmt_s_); 
  sqlite3_reset(this->stmt_s_);
}

db::Database::Database(const char *database) {
  /* Dangerous, no error checking. Fuck it. */
  sqlite3_open_v2(database, &db_, SQLITE_OPEN_READWRITE, NULL);
  sqlite3_prepare_v2(db_, "SELECT * FROM items WHERE ean=?1", -1, &stmt_, NULL);
  sqlite3_prepare_v2(db_, "SELECT * FROM cust WHERE id=?1", -1, &stmt_c_, NULL);
  sqlite3_prepare_v2(db_, "INSERT INTO \
                           sales \
                           (worker,\
                            customer,\
                            total,\
                            discount,\
                            items,\
                            quant)\
                           VALUES\
                           (?1,\
                            ?2,\
                            ?3,\
                            ?4,\
                            ?5,\
                            ?6)", -1, &stmt_s_, NULL);
  sqlite3_prepare_v2(db_, "UPDATE items SET stock=?1 WHERE ean=?2", -1, &stmt_i_, NULL);
}

db::Database::~Database() {
  sqlite3_close(db_);
}
