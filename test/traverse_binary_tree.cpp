#include "doctest/doctest.h"
#include "dsa/tree.hpp"

TEST_CASE("traverse binary tree") {
  dsa::BinaryTree<int> tree(0);
  tree.SetLeft(1);
  tree.SetRight(2);

  fmt::print("Pre Order\n");
  tree.PreOrder();

  fmt::print("In Order\n");
  tree.InOrder();

  fmt::print("Post Order\n");
  tree.PostOrder();

  CHECK(tree.Size() == 3);
}