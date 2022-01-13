#include "dsa/queue.hpp"

#include "doctest/doctest.h"

TEST_CASE("queue") {
  dsa::queue<int> q;
  CHECK(q.empty());
  CHECK(q.size() == 0);

  q.push(1);
  CHECK(!q.empty());
  CHECK(q.size() == 1);
  CHECK(q.pop() == 1);
  CHECK(q.empty());
  CHECK(q.size() == 0);

  q.push(1);
  q.push(2);
  q.push(3);
  CHECK(!q.empty());
  CHECK(q.size() == 3);
  CHECK(q.pop() == 1);

  CHECK(q.pop() == 2);
  CHECK(!q.empty());
  CHECK(q.size() == 1);
  CHECK(q.pop() == 3);

  CHECK(q.empty());
  CHECK(q.size() == 0);
}