add_executable(test_dynqueue test_dynqueue.cpp)
target_link_system_libraries(
            test_dynqueue
            PRIVATE
            default_warnings
            dynqueue
            Catch2::Catch2WithMain)
