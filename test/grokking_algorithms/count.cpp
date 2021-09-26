#include "dsa/grokking_algorithms/cha04/count.hpp"

#include <array>
#include <list>
#include <map>
#include <vector>

#include "doctest/doctest.h"

TEST_CASE("count with std::list") {
  using namespace dsa::grokking_algorithms::cha04;
  CHECK(count(std::list<int>{}) == 0);
  CHECK(count(std::list<int>{1, 2, 3}) == 3);
}

TEST_CASE("count with std::vector") {
  using namespace dsa::grokking_algorithms::cha04;
  CHECK(count(std::vector<int>{}) == 0);
  CHECK(count(std::vector<int>{1, 2, 3, 4}) == 4);
}

TEST_CASE("count with std::array") {
  using namespace dsa::grokking_algorithms::cha04;
  CHECK(count(std::array<int, 0>{}) == 0);
  CHECK(count(std::array<int, 4>{1, 2, 3, 4}) == 4);
}

TEST_CASE("count with std::map") {
  using namespace dsa::grokking_algorithms::cha04;
  CHECK(count(std::map<int, int>{}) == 0);
  CHECK(count(std::map<int, int>{{1, 1}, {2, 2}, {3, 3}}) == 3);
}