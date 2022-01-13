#pragma once

#include <utility>
#include <vector>

namespace dsa {

template <typename T>
class stack {
  using value_type = T;

 public:
  void push(value_type&& value) {
    data_.push_back(std::forward<value_type&&>(value));
  }

  value_type pop() {
    value_type value = data_.back();
    data_.pop_back();
    return value;
  }

  int top() { return data_.back(); }
  bool empty() { return data_.empty(); }
  int size() { return data_.size(); }

 private:
  std::vector<value_type> data_;
};

}  // namespace dsa