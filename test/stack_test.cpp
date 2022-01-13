#include "dsa/stack.hpp"

#include "doctest/doctest.h"

TEST_CASE("stack") {
  dsa::stack<int> s;
  CHECK(s.empty());
  CHECK(s.size() == 0);

  s.push(1);
  CHECK(!s.empty());
  CHECK(s.size() == 1);
  CHECK(s.top() == 1);

  s.push(2);
  CHECK(!s.empty());
  CHECK(s.size() == 2);
  CHECK(s.top() == 2);

  CHECK(s.pop() == 2);
  CHECK(!s.empty());
  CHECK(s.size() == 1);
  CHECK(s.top() == 1);

  CHECK(s.pop() == 1);
  CHECK(s.empty());
  CHECK(s.size() == 0);
}