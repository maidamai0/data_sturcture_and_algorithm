#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

namespace dsa::grokking_algorithms::cha04 {
using value_t = int;
using container_t = std::vector<value_t>;

namespace detail {
inline value_t max_element(const value_t& max_candidate,
                           const container_t& container,
                           typename container_t::const_iterator const& begin) {
  if (begin == container.cend()) {
    return max_candidate;
  }

  return std::max(max_candidate,
                  max_element(*begin, container, std::next(begin)));
}
}  // namespace detail

inline value_t max_element(const container_t& container) {
  return detail::max_element(std::numeric_limits<value_t>::min(), container,
                             container.cbegin());
}
}  // namespace dsa::grokking_algorithms::cha04