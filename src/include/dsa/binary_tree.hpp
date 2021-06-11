#pragma once

/**
 * @file tree.hpp
 * @author tonghao.yuan (yuantonghao@gmail.com)
 * @brief difinition of tree
 * @version 0.1
 * @date 2021-06-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <cstddef>
#include <memory>

#include "fmt/format.h"

namespace dsa {

namespace details {
template <typename T>
struct BinaryTreeNode {
  using value_type = T;
  using node_ptr = std::unique_ptr<BinaryTreeNode>;

  BinaryTreeNode(const value_type &value) : value_(value) {}

  value_type value_{};
  node_ptr left_;
  node_ptr right_;
};

template <typename T>
using TreeType = BinaryTreeNode<T>;

template <typename T>
void node_child(std::unique_ptr<TreeType<T>> &child, const T v) {
  if (child) {
    child->value_ = v;
  } else {
    child = std::make_unique<TreeType<T>>(v);
  }
}

template <typename T>
void node_print(const T &node) {
  fmt::print("{}\n", node->value_);
}

template <typename T>
void node_pre_order(const T &root) {
  if (!root) {
    return;
  }
  node_print(root);
  node_in_order(root->left_);
  node_in_order(root->right_);
}

template <typename T>
void node_in_order(const T &root) {
  if (!root) {
    return;
  }
  node_in_order(root->left_);
  node_print(root);
  node_in_order(root->right_);
}

template <typename T>
void node_post_order(const T &root) {
  if (!root) {
    return;
  }
  node_in_order(root->left_);
  node_in_order(root->right_);
  node_print(root);
}

template <typename T>
size_t node_size(const T &root) {
  if (!root) {
    return 0;
  }
  return 1 + node_size(root->left_) + node_size(root->right_);
}

}  // namespace details

template <typename T>
class BinaryTree {
 public:
  using value_type = T;
  using tree_node_ptr = std::unique_ptr<details::BinaryTreeNode<T>>;

  BinaryTree(const value_type &value)
      : root_(std::make_unique<details::BinaryTreeNode<T>>(value)) {}
  void SetLeft(const value_type &v) {
    return details::node_child(root_->left_, v);
  }

  void SetRight(const value_type &v) {
    return details::node_child(root_->right_, v);
  }

  void PreOrder() const { return details::node_pre_order(root_); }

  void PostOrder() const { return details::node_post_order(root_); }

  void InOrder() const { return details::node_in_order(root_); }

  auto Size() const -> size_t { return details::node_size(root_); }

 protected:
  tree_node_ptr root_;
};
}  // namespace dsa
