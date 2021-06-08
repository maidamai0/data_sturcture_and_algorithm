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
template <typename KeyType, typename ValueType>
class BinarySearchTree final {
 public:
  using key_type = KeyType;
  using value_type = ValueType;

  BinarySearchTree() = default;
  BinarySearchTree(const key_type& key, const value_type& value)
      : key_(std::make_optional<key_type>(key)), value_(value) {}

  void Emplace(const key_type& key, const value_type& value) {
    if (!key_) {
      key_ = std::make_optional<key_type>(key);
      value_ = value;
      return;
    }

    if (key < key_) {
      if (left_) {
        left_->Emplace(key, value);
      } else {
        left_ = std::make_unique<BinarySearchTree>(key, value);
      }

      return;
    }

    if (right_) {
      right_->Emplace(key, value);
    } else {
      right_ = std::make_unique<BinarySearchTree>(key, value);
    }
  }

  size_t Size() const {
    size_t cnt = 0;
    if (key_) {
      cnt += 1;
    }

    if (left_) {
      cnt += left_->Size();
    }
    if (right_) {
      cnt += right_->Size();
    }

    return cnt;
  }

  void InOrder() const {
    if (left_) {
      left_->InOrder();
    }

    if (key_) {
      print();
    }

    if (right_) {
      right_->InOrder();
    }
  }

  auto Get(const key_type& key) {
    if (key_ && key == key_) {
      return std::make_optional<value_type>(value_);
    }

    if (key < key_ && left_) {
      return left_->Get(key);
    }

    if (key >= key_ && right_) {
      return right_->Get(key);
    }

    return std::make_optional<value_type>();
  }

 private:
  void print() const { fmt::print("{}:{}\n", key_.value(), value_); }

 private:
  std::optional<key_type> key_;
  value_type value_;
  std::unique_ptr<BinarySearchTree> left_;
  std::unique_ptr<BinarySearchTree> right_;
};
}  // namespace dsa
