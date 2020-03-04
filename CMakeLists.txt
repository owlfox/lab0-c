cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(Catch2/single_include)

add_library(queue queue.c)
add_library(harness harness.c)
add_library(report report.c)
target_link_libraries(harness report)
target_link_libraries(queue harness)

add_library(catch2_runner tests/catch_main.cpp)
add_executable(queue_unit tests/test_queue.cpp)
target_link_libraries(queue_unit PRIVATE catch2_runner queue)

add_test(NAME queue_unit COMMAND queue_unit)

include(CTest)
