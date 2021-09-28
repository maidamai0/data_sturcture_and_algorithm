#include "dsa/grokking_algorithms/cha06/tree.hpp"

#include <iostream>

#include "doctest/doctest.h"

TEST_CASE("traverse tree with loop") {
  using namespace dsa::grokking_algorithms::cha06;
  auto* root = new detail::node{1, nullptr, nullptr};
  root->left = new detail::node{2, nullptr, nullptr};
  root->right = new detail::node{3, nullptr, nullptr};

  root->left->left = new detail::node{4, nullptr, nullptr};
  root->left->right = new detail::node{5, nullptr, nullptr};
  root->right->left = new detail::node{6, nullptr, nullptr};
  root->right->right = new detail::node{7, nullptr, nullptr};

  Tree tree{root};
  std::cout << tree.string();
  CHECK(tree.string() == "Tree: 1 2 3 4 5 6 7");
}