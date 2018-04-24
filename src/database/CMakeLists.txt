include_directories(${Shop_SOURCE_DIR}/include)

add_library(Database database.cpp)
target_link_libraries(Database sqlite3)
