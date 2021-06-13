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

#include "binary_search_tree.hpp"

namespace dsa {

template <typename KeyT, typename ValueT>
class AVLTree : public BinarySearchTree<KeyT, ValueT> {
 private:
  enum BalanceFactor { left = -1, equal, rihgt };
  BalanceFactor balance_factor_ = equal;
};
}  // namespace dsa
