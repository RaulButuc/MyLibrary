/**
 *  test_binary_search_tree.cpp
 *
 *  @author Raul Butuc.
 *  @version 1.0.2 02/11/2015
 */

// TODO: Update the Assert and Is classes for better custom data structures support.

#include <iostream>
#include "binary_search_tree.h"
#include "Assert.h"
#include "Is.h"

template <class _Tp> class binary_search_tree;

void print_tree(my_library::binary_search_tree<int>*);

int main(int argc, char* argv[]) {
  my_library::binary_search_tree<int> tree;
  std::vector<int> set_one = { 20, 17, 19, 15 };
  std::vector<int> set_two = { 11, 8, 14 };

  tree.insert(10);
  tree.insert(8);
  tree.insert(9);
  tree.insert(5);
  tree.insert(14);
  tree.insert(set_one);

  print_tree(&tree);

  tree.remove(set_two);

  print_tree(&tree);

  system("pause");

  return 0;
}

void print_tree(my_library::binary_search_tree<int>* tree) {
  tree->display_pre_order();
  std::cout << "\n";
  tree->display_in_order();
  std::cout << "\n";
  tree->display_post_order();
  std::cout << "\n";
}
