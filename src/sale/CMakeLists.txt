include_directories(${Shop_SOURCE_DIR}/include)
add_library(Sale sale.cpp)
target_link_libraries(Sale Display)
