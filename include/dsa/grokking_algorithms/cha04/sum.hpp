#pragma once

#include <vector>

namespace dsa::grokking_algorithms::cha04 {

namespace details {

inline int sum(const std::vector<int> &nums, int start = 0) {
  if (start == nums.size()) {
    return 0;
  }

  return nums[start] + sum(nums, start + 1);
}

}  // namespace details

inline int sum(const std::vector<int> &nums) {
  return details::sum(nums);
}

}  // namespace dsa::grokking_algorithms::cha04