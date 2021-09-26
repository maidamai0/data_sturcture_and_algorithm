#pragma once

#include <list>

namespace dsa::grokking_algorithms::cha04 {

namespace details {

template <typename Container>
inline int count(const Container &nums,
                 const typename Container::const_iterator begin) {
  if (begin == nums.cend()) {
    return 0;
  }

  return 1 + count(nums, std::next(begin));
}

}  // namespace details

template <typename Container>
inline int count(const Container &nums) {
  return details::count(nums, nums.cbegin());
}

}  // namespace dsa::grokking_algorithms::cha04