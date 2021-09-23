#include "dsa/grokking_algorithms/cha01/binary_search.hpp"

#include "doctest/doctest.h"

TEST_CASE("binary_search") {
  using namespace dsa::grokking_algorithms::cha01;
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  CHECK(binary_search(v, 1)->first == 0);
  CHECK(binary_search(v, 2)->first == 1);
  CHECK(binary_search(v, 3)->first == 2);
  CHECK(binary_search(v, 4)->first == 3);
  CHECK(binary_search(v, 5)->first == 4);
  CHECK(binary_search(v, 6)->first == 5);
  CHECK(binary_search(v, 7)->first == 6);
  CHECK(binary_search(v, 8)->first == 7);
  CHECK(binary_search(v, 9)->first == 8);
  CHECK(binary_search(v, 10)->first == 9);
  CHECK(!binary_search(v, 11));
}