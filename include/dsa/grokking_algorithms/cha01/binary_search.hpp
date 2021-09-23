#pragma once

#include <optional>
#include <utility>
#include <vector>

namespace dsa::grokking_algorithms::cha01 {

using value_t = int;
using sorted_list_t = std::vector<value_t>;
using result_t = std::optional<std::pair<sorted_list_t::size_type, value_t>>;

inline result_t binary_search(const sorted_list_t& sorted_list, value_t value) {
  const auto size = sorted_list.size();
  if (size == 0) {
    return std::nullopt;
  }

  auto left = 0;
  auto right = size - 1;
  while (left <= right) {
    const auto mid = (left + right) / 2;
    if (sorted_list[mid] == value) {
      return std::make_pair(mid, value);
    } else if (sorted_list[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return std::nullopt;
}

}  // namespace dsa::grokking_algorithms::cha01
