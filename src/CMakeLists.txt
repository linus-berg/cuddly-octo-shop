include_directories(${Shop_SOURCE_DIR}/include)

# Libs
add_subdirectory(cart)
add_subdirectory(database)
add_subdirectory(sale)
add_subdirectory(controller)

add_executable(Shop main.cpp)
target_link_libraries(Shop Controller Sale Cart Database)
