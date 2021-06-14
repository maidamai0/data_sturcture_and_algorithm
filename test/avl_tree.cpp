#include "dsa/avl_tree.hpp"

#include <string>

#include "doctest/doctest.h"

TEST_CASE("avltree") {
  dsa::AVLTree<int, std::string> tree;
  tree.Emplace(0, "one");
  tree.Emplace(1, "two");
  tree.Emplace(2, "three");
  CHECK(!tree.Balance());

  tree.InOrder();
  tree.LeftRotate();
  CHECK(tree.Balance());
  tree.InOrder();
}