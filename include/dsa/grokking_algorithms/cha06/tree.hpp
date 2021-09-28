#pragma once

#include <cassert>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

namespace dsa::grokking_algorithms::cha06 {
using value_t = int;
namespace detail {
struct node {
  value_t value;
  node* left;
  node* right;
};
}  // namespace detail

class Tree {
 public:
  Tree(detail::node* node) : root_(node) {}

  std::string string() const {
    assert(root_);

    std::ostringstream ss;
    ss << "Tree: ";
    std::list<detail::node*> nodes;
    nodes.push_back(root_);

    while (!nodes.empty()) {
      detail::node* node = nodes.front();
      nodes.pop_front();

      ss << node->value << " ";

      if (node->left) {
        nodes.push_back(node->left);
      }

      if (node->right) {
        nodes.push_back(node->right);
      }
    }

    return ss.str().substr(0, ss.str().size() - 1);
  }

 private:
  detail::node* root_ = nullptr;
};
}  // namespace dsa::grokking_algorithms::cha06