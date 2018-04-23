include_directories(${Shop_SOURCE_DIR}/include)
add_subdirectory(cart)

add_executable(Shop main.cpp)
target_link_libraries(Shop Cart)
