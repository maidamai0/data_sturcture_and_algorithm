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

#include "fmt/format.h"

namespace dsa {

template <typename T>
class BinaryTree {
 public:
  using value_type = T;

  BinaryTree(const value_type &value) : value_(value) {}
  void SetLeft(const value_type &left) {
    if (left_) {
      delete left_;
    }

    left_ = new BinaryTree(left);
  }

  void SetRight(const value_type &right) {
    if (right_) {
      delete right_;
    }

    right_ = new BinaryTree(right);
  }

  void PreOrder() const {
    print();
    if (left_) {
      left_->print();
    }

    if (right_) {
      right_->print();
    }
  }

  void PostOrder() const {
    if (left_) {
      left_->print();
    }

    if (right_) {
      right_->print();
    }

    print();
  }

  void InOrder() const {
    if (left_) {
      left_->print();
    }

    print();

    if (right_) {
      right_->print();
    }
  }

  auto Size() const -> size_t {
    std::size_t cnt = 1;
    if (left_) {
      cnt += left_->Size();
    }

    if (right_) {
      cnt += right_->Size();
    }

    return cnt;
  }

 private:
  void print() const { fmt::print("{}\n", value_); }

 private:
  value_type value_;
  BinaryTree *left_ = nullptr;
  BinaryTree *right_ = nullptr;
};
}  // namespace dsa
