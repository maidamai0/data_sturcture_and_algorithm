#pragma once

#include <limits>
#include <tuple>
#include <utility>
#include <vector>

namespace dsa::grokking_algorithms::cha02 {
using value_t = int;
using Sequence = std::vector<value_t>;

namespace details {
std::pair<size_t, value_t> min(const Sequence& sequence) {
  auto min_index = 0;
  auto min_value = std::numeric_limits<value_t>::max();
  for (size_t i = 0; i < sequence.size(); ++i) {
    if (sequence[i] < min_value) {
      min_index = i;
      min_value = sequence[i];
    }
  }

  return std::make_pair(min_index, min_value);
}
}  // namespace details

// Selection Sort
void selection_sort(Sequence& sequence) {
  Sequence sorted;
  for (auto i = 0; i < sequence.size(); ++i) {
    auto [min_index, min_value] = details::min(sequence);
  }
}
}  // namespace dsa::grokking_algorithms::cha02