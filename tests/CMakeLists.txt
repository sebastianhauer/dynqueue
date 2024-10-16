add_executable(test_dynqueue test_dynqueue.cpp)
target_link_system_libraries(
            test_dynqueue
            PRIVATE
            default_warnings
            dynqueue
            Catch2::Catch2WithMain)

target_compile_options(test_dynqueue PRIVATE -fsanitize=address,undefined)
target_link_options(test_dynqueue PRIVATE -fsanitize=address,undefined)

add_test(NAME test_dynqueue COMMAND test_dynqueue)
add_test(NAME test_dynqueue_memchecked 
         COMMAND valgrind 
         --error-exitcode=1
         --tool=memcheck
         --leak-check=full
         --errors-for-leak-kinds=definite
         --show-leak-kinds=definite $<TARGET_FILE:test_dynqueue>
         WORKING_DIRECTORY 
         ${CMAKE_CURRENT_LIST_DIR})
