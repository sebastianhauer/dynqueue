#include <catch2/catch_test_macros.hpp>

#include <dynqueue/dynqueue.hpp>

TEST_CASE("new queues are empty and have the expected capacity") {
    auto q = dynqueue<int>(16);
    REQUIRE(q.size() == 0);
    REQUIRE(q.capacity() == 16);
}

TEST_CASE("queue size increases while enqueing") {
    auto q = dynqueue<int>(2);
    q.enqueue(1);
    REQUIRE(q.size() == 1);
    q.enqueue(2);
    REQUIRE(q.size() == 2);
    q.enqueue(3);
    REQUIRE(q.size() == 3);
}

TEST_CASE("queue capacity should double") {
    auto q = dynqueue<int>(1);
    REQUIRE(q.capacity() == 1);
    q.enqueue(1);
    REQUIRE(q.capacity() == 1);
    q.enqueue(2);
    REQUIRE(q.capacity() == 2);
    q.enqueue(3);
    REQUIRE(q.size() == 3);
    REQUIRE(q.capacity() == 4);
}

TEST_CASE("queue should dequeue from the front and the size should change") {
    auto q = dynqueue<int>(16);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    REQUIRE(q.size() == 3);

    REQUIRE(q.dequeue() == 1);
    REQUIRE(q.size() == 2);

    REQUIRE(q.dequeue() == 2);
    REQUIRE(q.size() == 1);

    REQUIRE(q.dequeue() == 3);
    REQUIRE(q.size() == 0);
}

TEST_CASE(
    "the capacity should not change when enquing and dequeue repeatedly") {
    auto q = dynqueue<int>(2);
    q.enqueue(1);
    q.enqueue(2);
    REQUIRE(q.capacity() == 2);

    REQUIRE(q.dequeue() == 1);
    REQUIRE(q.capacity() == 2);

    q.enqueue(3);
    REQUIRE(q.capacity() == 2);

    REQUIRE(q.dequeue() == 2);
    REQUIRE(q.capacity() == 2);
}
