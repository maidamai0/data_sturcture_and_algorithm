#pragma once
/**
 * @file binary_search_tree.hpp
 * @author tonghao.yuan (tonghao.yuan@csdental.com)
 * @brief   Binary search tree
 * @version 0.1
 * @date 2021-06-08
 *
 */

#include "binary_tree.hpp"

namespace dsa {
template <typename KeyType, typename ValueType>
class BinarySearchTree final : public BinaryTree<ValueType> {
 public:
  using key_type = KeyType;
  using base_type = BinaryTree<ValueType>;

  BinarySearchTree(const key_type& key,
                   const typename base_type::value_type& value)
      : base_type(value), key_(key) {}

 private:
  void print() const override { fmt::print("{}:{}\n", key_, this->value_); }

 private:
  key_type key_;
};
}  // namespace dsa
