#include "dsa/binary_search_tree.hpp"

#include <string>

#include "doctest/doctest.h"

TEST_CASE("simple binary search tree") {
  dsa::BinarySearchTree<int, std::string> tree;
  tree.Emplace(0, "zero");
  tree.Emplace(1, "one");
  tree.Emplace(2, "two");
  tree.Emplace(3, "three");
  tree.Emplace(4, "four");
  tree.Emplace(5, "five");
  tree.InOrder();
  CHECK(tree.Get(0) == "zero");
  CHECK(tree.Get(3) == "three");
  CHECK(tree.Size() == 6);
}