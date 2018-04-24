#include "database.h"

db::ItemDTO* db::Database::GetItem(std::string ean) {
  return new ItemDTO(ean, "Watermelon", ".", 0.99);
}
