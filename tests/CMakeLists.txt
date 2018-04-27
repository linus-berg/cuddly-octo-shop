set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Shop_SOURCE_DIR}/bin)
include_directories(${Shop_SOURCE_DIR}/include)
add_subdirectory(./googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(ctrlTest ctrl.cpp)
# Standard linking to gtest stuff.
target_link_libraries(ctrlTest gtest gtest_main)

  # Extra linking for the project.
target_link_libraries(ctrlTest Controller Database Sale Cart)

add_executable(saleTest sale.cpp)
# Standard linking to gtest stuff.
target_link_libraries(saleTest gtest gtest_main)
# Extra linking for the project.
target_link_libraries(saleTest Controller Database Sale Cart)

add_executable(dbTest db.cpp)
# Standard linking to gtest stuff.
target_link_libraries(dbTest gtest gtest_main)
# Extra linking for the project.
target_link_libraries(dbTest Controller Database Sale Cart)

add_test(NAME DB-Test COMMAND dbTest)
add_test(NAME Sale-Test COMMAND saleTest)
add_test(NAME Controller-Test COMMAND ctrlTest)
