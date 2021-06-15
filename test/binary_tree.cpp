#include "dsa/binary_tree.hpp"

#include "doctest/doctest.h"

TEST_CASE("traverse binary tree") {
  dsa::BinaryTree<int> tree(0);
  CHECK(tree.Height() == 0);
  tree.SetLeft(1);
  CHECK(tree.Height() == 1);
  tree.SetRight(2);
  CHECK(tree.Height() == 1);

  fmt::print("Pre Order\n");
  tree.PreOrder();

  fmt::print("In Order\n");
  tree.InOrder();

  fmt::print("Post Order\n");
  tree.PostOrder();

  CHECK(tree.Size() == 3);
}