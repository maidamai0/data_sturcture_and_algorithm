#pragma once

#include <optional>
#include <utility>
#include <vector>

namespace dsa::grokking_algorithms::cha01 {

template <typename ValueType, typename SortedSequence = std::vector<ValueType>,
          typename SizeType = typename SortedSequence::size_type,
          typename ResultType = std::tuple<bool, SizeType, SizeType>>
inline ResultType binary_search(const SortedSequence& sorted_list,
                                ValueType value) {
  const auto size = sorted_list.size();
  if (size == 0) {
    return {false, {}, {}};
  }

  auto left = 0;
  auto right = size - 1;
  SizeType steps = 0;

  // right may overflow, so we check for it
  while (left <= right && right < size) {
    ++steps;
    const auto mid = (left + right) / 2;
    if (sorted_list[mid] == value) {
      return {true, mid, steps};
    } else if (sorted_list[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return {false, {}, {}};
}

}  // namespace dsa::grokking_algorithms::cha01
