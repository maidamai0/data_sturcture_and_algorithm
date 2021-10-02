#include "dsa/grokking_algorithms/cha07/dijkstra_algorithm.hpp"

#include <list>

#include "doctest/doctest.h"

constexpr auto kStart = "start";
constexpr auto kA = "A";
constexpr auto kB = "B";
constexpr auto kFIN = "FIN";

TEST_CASE("Dijkstra Algorithm") {
  using namespace dsa::grokking_algorithms::cha07;

  graph_t graph;
  graph[kStart] = {{kA, 6}, {kB, 2}};
  graph[kA] = {{kFIN, 1}};

  graph[kB] = {{kA, 3}, {kFIN, 5}};
  graph[kFIN] = {};

  auto result = dijkstra(graph, kStart);
  CHECK(result[kStart] == 0);
  CHECK(result[kA] == 6);
  CHECK(result[kB] == 2);
  CHECK(result[kFIN] == 6);
}