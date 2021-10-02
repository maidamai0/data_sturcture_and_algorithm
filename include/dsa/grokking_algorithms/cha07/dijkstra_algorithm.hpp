#pragma once

#include <cstddef>
#include <list>
#include <string>
#include <unordered_map>

namespace dsa::grokking_algorithms::cha07 {

using key_t = std::string;

namespace detail {

struct edge {
  key_t to;
  std::size_t weight;
};

struct cost {
  std::size_t cost;
  key_t parent;
};
using cost_t = std::unordered_map<key_t, cost>;

}  // namespace detail

using edge_t = detail::edge;
using graph_t = std::unordered_map<key_t, std::list<edge_t>>;

std::size_t dijkstra(const graph_t& graph, const key_t from, const key_t& to) {
  detail::cost_t costs;
}

}  // namespace dsa::grokking_algorithms::cha07