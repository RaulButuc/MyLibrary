/**
*  test_graph.cpp
*
*  @author Raul Butuc
*/

// Not yet updated to make use of the custom unit test framework.

#include <iostream>
#include "graph.h"
#include "Assert.h"
#include "Is.h"

using std::cout;
using my_library::graph;
using my_library::Assert;
using my_library::Is;

auto test_forward_list_one() -> void;

int main(int argc, char* argv[]) {

  test_forward_list_one();

  system("pause");

  return 0;
}

auto test_forward_list_one() -> void {
  graph<int> g(GRAPH_TYPE::Undirected, false);
}
