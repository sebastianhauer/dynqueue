#include <catch2/catch_test_macros.hpp>

#include <dynqueue/dynqueue.hpp>

TEST_CASE("main")
{
    auto q = dynqueue(16);
    q.enqueue(1);
    q.enqueue(2);
}
