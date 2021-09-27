#pragma once

#include <iterator>
#include <vector>

namespace dsa::grokking_algorithms::cha04 {

using value_t = int;
using container_t = std::vector<value_t>;

namespace detail {
inline void quick_sort(container_t& container) {
  if (container.size() < 2) {
    return;
  }

  if (container.size() == 2) {
    if (container[0] > container[1]) {
      std::swap(container[0], container[1]);
    }
    return;
  }

  container_t less;
  container_t bigger;
  const value_t pivot = container[0];
  for (auto it = std::next(container.begin()); it != container.end(); ++it) {
    if (*it < pivot) {
      less.push_back(*it);
    } else {
      bigger.push_back(*it);
    }
  }

  quick_sort(less);
  quick_sort(bigger);
  container.clear();
  std::copy(less.begin(), less.end(), std::back_inserter(container));
  container.push_back(pivot);
  std::copy(bigger.begin(), bigger.end(), std::back_inserter(container));
}

}  // namespace detail

inline void quick_sort(container_t& container) {
  detail::quick_sort(container);
}
}  // namespace dsa::grokking_algorithms::cha04