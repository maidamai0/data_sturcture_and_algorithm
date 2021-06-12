#include <string>

#include "doctest/doctest.h"
#include "dsa/binary_search_tree.hpp"

TEST_CASE("simple binary search tree") {
  dsa::BinarySearchTree<int, std::string> tree;
  tree.Emplace(3, "three");
  CHECK(tree.Height() == 0);
  tree.Emplace(2, "two");
  tree.Emplace(1, "one");
  tree.Emplace(0, "zero");
  CHECK(!tree.Balance());
  CHECK(tree.Height() == 3);
  tree.Emplace(4, "four");
  tree.Emplace(5, "five");
  CHECK(tree.Balance());
  CHECK(tree.Height() == 3);
}