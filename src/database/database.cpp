#include "database.h"

db::ItemDTO db::Database::GetItem() {
  return ItemDTO("123", "Watermelon", ".", 0.99);
}
