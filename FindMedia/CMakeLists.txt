add_executable(heap_test heap_test.cc)
target_link_libraries(heap_test gtest gtest_main)

add_executable(generator_test generator_test.cc)
target_link_libraries(generator_test gtest gtest_main)

add_executable(repeatable_stream_test repeatable_stream_test.cc)
target_link_libraries(repeatable_stream_test gtest gtest_main)

add_executable(solution_test solution.cc solution_test.cc)
target_link_libraries(solution_test gtest gtest_main)
