#include <catch2/catch.hpp>
extern "C" {
#include <string.h>
#include "queue.h"
#define N 128
TEST_CASE("qsize inited to be 0")
{
    queue_t *q = q_new();
    REQUIRE(q_size(q) == 0);
}

TEST_CASE("inserti/remove head")
{
    queue_t *q = q_new();
    char sp[N];
    q_insert_head(q, "123");
    REQUIRE(q_size(q) == 1);
    REQUIRE(strcmp(q->head->value, "123") == 0);

    REQUIRE(q_remove_head(q, sp, N) == true);
    REQUIRE(q_remove_head(q, sp, N) == false);
}
};
