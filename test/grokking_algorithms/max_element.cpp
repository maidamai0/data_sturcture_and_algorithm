#include "dsa/grokking_algorithms/cha04/max_element.hpp"

#include "doctest/doctest.h"

TEST_CASE("max_element") {
  using namespace dsa::grokking_algorithms::cha04;
  CHECK(max_element({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) == 10);
}