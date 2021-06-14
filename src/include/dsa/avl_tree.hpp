#pragma once

/**
 * @file avl_tree.hpp
 * @author tonghao.yuan (yuantonghao@gmail.com)
 * @brief   AVL tree
 * @version 0.1
 * @date 2021-06-13
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <memory>
#include <utility>

#include "dsa/avl_tree.hpp"
#include "dsa/binary_search_tree.hpp"

namespace dsa {

namespace details {

template <typename KeyT, typename ValueT>
auto node_left_rotation(NodePtr<KeyT, ValueT> root) {
  auto new_root = root->right_;
  root->right_ = nullptr;
  new_root->left_ = root;

  return new_root;
}

template <typename KeyT, typename ValueT>
auto node_right_rotation(NodePtr<KeyT, ValueT> root) {
  auto& new_root = root->left_;
  root->left_ = nullptr;
  new_root->right_ = root;
  return new_root;
}
}  // namespace details

template <typename KeyT, typename ValueT>
class AVLTree : public BinarySearchTree<KeyT, ValueT> {
 public:
  void LeftRotate() { this->root_ = details::node_left_rotation(this->root_); }
  void RightRotate() {
    this->root_ = details::node_right_rotation(this->root_);
  }

 private:
  enum BalanceFactor { left = -1, equal, rihgt };
  BalanceFactor balance_factor_ = equal;
};
}  // namespace dsa
