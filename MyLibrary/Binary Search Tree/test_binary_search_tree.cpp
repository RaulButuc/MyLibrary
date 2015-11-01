/**
 *  test_binary_search_tree.cpp
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 20/10/2015
 */

/*
  TODO: Update the Assert.h and Is.h classes for better
        custom data structures support.
*/

#include <iostream>
#include "binary_search_tree.h"
#include "Assert.h"
#include "Is.h"

template <class _Tp> class binary_search_tree;

int main(int argc, char* argv[]) {
  my_library::binary_search_tree<int> tree;
  std::vector<int> values = { 20, 17, 19, 15 };

  tree.insert(10);
  tree.insert(8);
  tree.insert(9);
  tree.insert(5);
  tree.insert(14);
  tree.insert(values);

  tree.displayPreOrder();
  std::cout << "\n";
  tree.displayInOrder();
  std::cout << "\n";
  tree.displayPostOrder();
  std::cout << "\n";

  system("pause");

  return 0;
}