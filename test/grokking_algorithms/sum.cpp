#include "dsa/grokking_algorithms/cha04/sum.hpp"

#include <vector>

#include "doctest/doctest.h"

TEST_CASE("sum") {
  using namespace dsa::grokking_algorithms::cha04;
  CHECK(sum(std::vector<int>{1, 2, 3, 4, 5}) == 15);
}