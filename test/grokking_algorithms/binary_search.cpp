#include "dsa/grokking_algorithms/cha01/binary_search.hpp"

#include "doctest/doctest.h"

TEST_CASE("binary_search") {
  using namespace dsa::grokking_algorithms::cha01;
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  {
    const auto [found, index, steps] = binary_search(v, 0);
    CHECK(!found);
  }

  {
    const auto [found, index, steps] = binary_search(v, 1);
    CHECK(found);
    CHECK(index == 0);
    CHECK(steps <= 4);
  }

  {
    const auto [found, index, steps] = binary_search(v, 2);
    CHECK(found);
    CHECK(index == 1);
    CHECK(steps <= 4);
  }

  {
    const auto [found, index, steps] = binary_search(v, 3);
    CHECK(found);
    CHECK(index == 2);
    CHECK(steps <= 4);
  }

  {
    const auto [found, index, steps] = binary_search(v, 4);
    CHECK(found);
    CHECK(index == 3);
    CHECK(steps <= 4);
  }

  {
    const auto [found, index, steps] = binary_search(v, 5);
    CHECK(found);
    CHECK(index == 4);
    CHECK(steps <= 4);
  }

  {
    const auto [found, index, steps] = binary_search(v, 6);
    CHECK(found);
    CHECK(index == 5);
    CHECK(steps <= 4);
  }

  {
    const auto [found, index, steps] = binary_search(v, 7);
    CHECK(found);
    CHECK(index == 6);
    CHECK(steps <= 4);
  }

  {
    const auto [found, index, steps] = binary_search(v, 8);
    CHECK(found);
    CHECK(index == 7);
    CHECK(steps <= 4);
  }

  {
    const auto [found, index, steps] = binary_search(v, 9);
    CHECK(found);
    CHECK(index == 8);
    CHECK(steps <= 4);
  }

  {
    const auto [found, index, steps] = binary_search(v, 10);
    CHECK(found);
    CHECK(index == 9);
    CHECK(steps <= 4);
  }
}