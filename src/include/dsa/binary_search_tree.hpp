#pragma once
/**
 * @file binary_search_tree.hpp
 * @author tonghao.yuan (tonghao.yuan@csdental.com)
 * @brief   Binary search tree
 * @version 0.1
 * @date 2021-06-08
 *
 */

#include <memory>
#include <optional>

#include "fmt/format.h"

namespace dsa {

namespace details {
template <typename KeyType, typename ValueType>
struct BinarySearchTreeNode {
  using key_type = KeyType;
  using value_type = ValueType;

  BinarySearchTreeNode(const key_type& key, const value_type& value)
      : key_(key), value_(value) {}

  key_type key_;
  value_type value_;
  std::unique_ptr<BinarySearchTreeNode> left_;
  std::unique_ptr<BinarySearchTreeNode> right_;
};

template <typename KeyType, typename ValueType,
          typename NodeType = BinarySearchTreeNode<KeyType, ValueType>,
          typename NodePtr =
              std::unique_ptr<BinarySearchTreeNode<KeyType, ValueType>>>
void node_insert(NodePtr& root, const KeyType& key, const ValueType& value) {
  if (!root) {
    root = std::make_unique<NodeType>(key, value);
    return;
  }

  if (key < root->key_) {
    node_insert(root->left_, key, value);
  } else {
    node_insert(root->right_, key, value);
  }
}

template <typename NodePtr>
auto node_size(const NodePtr& root) {
  if (!root) {
    return size_t(0);
  }

  size_t cnt = 1;
  cnt += node_size(root->left_);
  cnt += node_size(root->right_);

  return cnt;
}

template <typename NodePtr>
void node_in_order(const NodePtr& root) {
  if (!root) {
    return;
  }

  node_in_order(root->left_);
  fmt::print("{}:{}\n", root->key_, root->value_);
  node_in_order(root->right_);
}

}  // namespace details

template <typename KeyType, typename ValueType>
class BinarySearchTree final {
 public:
  using tree_node_t = details::BinarySearchTreeNode<KeyType, ValueType>;
  using tree_node_ptr = std::unique_ptr<tree_node_t>;
  using key_type = typename tree_node_t::key_type;
  using value_type = typename tree_node_t::value_type;

  BinarySearchTree() = default;

  void Emplace(const key_type& key, const value_type& value) {
    node_insert(root_, key, value);
  }
  size_t Size() const { return node_size(root_); }
  void InOrder() const { return node_in_order(root_); }
  auto Get(const key_type& key) { return node_get(root_, key); }

 private:
  // TODO (tonghao): 2021-06-09
  // move out of class
  static auto node_get(const tree_node_ptr& root, const key_type& key) {
    if (!root) {
      return std::make_optional<ValueType>();
    }

    if (key == root->key_) {
      return std::make_optional<ValueType>(root->value_);
    }

    if (key < root->key_) {
      return node_get(root->left_, key);
    }

    return node_get(root->right_, key);
  }

 private:
  tree_node_ptr root_;
};
}  // namespace dsa
