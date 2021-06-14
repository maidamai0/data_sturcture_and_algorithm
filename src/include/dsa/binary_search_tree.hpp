#pragma once
/**
 * @file binary_search_tree.hpp
 * @author tonghao.yuan (tonghao.yuan@csdental.com)
 * @brief   Binary search tree
 * @version 0.1
 * @date 2021-06-08
 *
 */

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <optional>

#include "dsa/binary_search_tree.hpp"
#include "fmt/format.h"

namespace dsa {

namespace details {
template <typename KeyType, typename ValueType>
struct BinarySearchTreeNode {
  using key_type = KeyType;
  using value_type = ValueType;

  BinarySearchTreeNode(const key_type& key, const value_type& value)
      : key_(key), value_(value) {}

  ~BinarySearchTreeNode() {
    delete left_;
    delete right_;
  }

  key_type key_;
  value_type value_;
  BinarySearchTreeNode* left_ = nullptr;
  BinarySearchTreeNode* right_ = nullptr;
};

template <typename KeyT, typename ValueT>
using NodeType = BinarySearchTreeNode<KeyT, ValueT>;

template <typename KeyT, typename ValueT>
using NodePtr = BinarySearchTreeNode<KeyT, ValueT>*;

template <typename KeyT, typename ValueT>
void node_insert(NodePtr<KeyT, ValueT>& root, const KeyT& key,
                 const ValueT& value) {
  if (!root) {
    root = new NodeType<KeyT, ValueT>(key, value);
    return;
  }

  if (key < root->key_) {
    node_insert(root->left_, key, value);
  } else {
    node_insert(root->right_, key, value);
  }
}

template <typename NodePtr>
auto node_size(const NodePtr root) {
  if (!root) {
    return size_t(0);
  }

  size_t cnt = 1;
  cnt += node_size(root->left_);
  cnt += node_size(root->right_);

  return cnt;
}

template <typename NodePtr>
void node_in_order(const NodePtr root) {
  if (!root) {
    return;
  }

  node_in_order(root->left_);
  fmt::print("{}:{}\n", root->key_, root->value_);
  node_in_order(root->right_);
}

template <typename KeyT, typename ValueT>
auto node_get(const NodePtr<KeyT, ValueT> root, const KeyT& key) {
  if (!root) {
    return std::make_optional<ValueT>();
  }

  if (key == root->key_) {
    return std::make_optional<ValueT>(root->value_);
  }

  if (key < root->key_) {
    return node_get(root->left_, key);
  }

  return node_get(root->right_, key);
}

template <typename KeyT, typename ValueT>
auto node_height(const NodePtr<KeyT, ValueT> root) {
  if (!root) {
    return 0;
  }

  return 1 + std::max(node_height(root->left_), node_height(root->right_));
}

template <typename KeyT, typename ValueT>
bool node_is_balance(const NodePtr<KeyT, ValueT> root) {
  return std::abs(node_height(root->left_) - node_height(root->right_)) <= 1;
}

}  // namespace details

template <typename KeyType, typename ValueType>
class BinarySearchTree {
 public:
  using tree_node_t = details::BinarySearchTreeNode<KeyType, ValueType>;
  using tree_node_ptr = tree_node_t*;
  using key_type = typename tree_node_t::key_type;
  using value_type = typename tree_node_t::value_type;

  BinarySearchTree() = default;
  ~BinarySearchTree() { delete root_; }

  void Emplace(const key_type& key, const value_type& value) {
    node_insert(root_, key, value);
  }
  size_t Size() const { return node_size(root_); }
  void InOrder() const { return node_in_order(root_); }
  auto Get(const key_type& key) { return node_get(root_, key); }
  auto Height() const { return details::node_height(root_) - 1; }
  auto Balance() const { return details::node_is_balance(root_); }

 protected:
  tree_node_ptr root_ = nullptr;
};
}  // namespace dsa
