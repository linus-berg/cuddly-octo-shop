include_directories(${Shop_SOURCE_DIR}/include)
SET( CMAKE_CXX_FLAGS  "-DSQLITE_DEBUG" )
add_library(Database database.cpp)
target_link_libraries(Database sqlite3)
