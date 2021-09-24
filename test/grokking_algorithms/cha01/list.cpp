#include "dsa/grokking_algorithms/cha02/list.hpp"

#include <string>

#include "doctest/doctest.h"

TEST_CASE("list_int") {
  using namespace dsa::grokking_algorithms::cha02;
  list<int> l(4);
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);
  l.push_front(3);
  l.push_front(2);
  l.push_front(1);

  CHECK(l.size() == 7);

  l.print();
}

TEST_CASE("list_string") {
  using namespace dsa::grokking_algorithms::cha02;
  list<std::string> l("4");
  l.push_back("5");
  l.push_back("6");
  l.push_back("7");
  l.push_front("3");
  l.push_front("2");
  l.push_front("1");

  CHECK(l.size() == 7);

  l.print();
}