#pragma once

#include <vcruntime.h>

#include <cassert>
#include <iostream>
#include <optional>
#include <utility>
#include <vector>

namespace dsa::grokking_algorithms::cha02 {

// using value_type = int;

template <typename T>
class list {
  using value_type = T;

 public:
  list() = default;
  list(const value_type& value) : head_(new node(value)) {}

  void push_back(const value_type& value) {
    const auto new_node = new node(value);
    if (head_ == nullptr) {
      head_ = new_node;
    } else if (tail_ == nullptr) {
      tail_ = new_node;
      head_->next_ = tail_;
    } else {
      tail_->next_ = new_node;
      tail_ = new_node;
    }
  }

  void push_front(const value_type& value) {
    const auto new_node = new node(value);
    if (head_ == nullptr) {
      head_ = new_node;
    } else {
      new_node->next_ = head_;
      head_ = new_node;
    }
  }

  void pop_back() {
    if (head_ == nullptr) {
      assert(false);
      return;
    }

    if (head_->next_ == nullptr) {
      delete head_;
      head_ = nullptr;
    } else {
      delete head_->next_;
      head_->next_ = nullptr;
    }
  }

  void pop_front() {
    if (head_ == nullptr) {
      assert(false);
      return;
    }

    if (head_->prev_ == nullptr) {
      delete head_;
      head_ = nullptr;
    } else {
      delete head_->prev_;
      head_->prev_ = nullptr;
    }
  }

  void print() const {
    auto cur = head_;
    while (cur != nullptr) {
      std::cout << cur->value_ << " ";
      cur = cur->next_;
    }
  }

  size_t size() const {
    size_t size = 0;
    auto cur = head_;
    while (cur != nullptr) {
      ++size;
      cur = cur->next_;
    }

    return size;
  }

 private:
  struct node {
    using value_t = value_type;

    explicit node(const value_t& value) : value_(value) {}
    value_t value_ = 0;
    node* next_ = nullptr;
    node* prev_ = nullptr;
  };

  node* head_ = nullptr;
  node* tail_ = nullptr;
};

}  // namespace dsa::grokking_algorithms::cha02
