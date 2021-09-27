#include "dsa/grokking_algorithms/cha04/quick_sort.hpp"

#include <algorithm>
#include <vector>

#include "doctest/doctest.h"

TEST_CASE("quick sort array") {
  using namespace dsa::grokking_algorithms::cha04;
  std::vector<int> unsorted{2, 3, 1, 5, 6, 7, 4};
  auto unsorted_1 = unsorted;
  quick_sort(unsorted);
  std::sort(unsorted_1.begin(), unsorted_1.end());

  CHECK(unsorted == unsorted_1);
}