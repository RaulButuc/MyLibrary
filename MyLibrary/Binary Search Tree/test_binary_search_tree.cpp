/**
 *  test_binary_search_tree.cpp
 *
 *  @author Raul Butuc.
 *  @version 1.0.1 01/11/2015
 */

// TODO: Update the Assert and Is classes for better custom data structures support.

#include <iostream>
#include "binary_search_tree.h"
#include "Assert.h"
#include "Is.h"

template <class _Tp> class binary_search_tree;

void printTree(my_library::binary_search_tree<int>*);

int main(int argc, char* argv[]) {
  my_library::binary_search_tree<int> tree;
  std::vector<int> setOneValues = { 20, 17, 19, 15 };
  std::vector<int> setTwoValues = { 11, 8, 14 };

  tree.insert(10);
  tree.insert(8);
  tree.insert(9);
  tree.insert(5);
  tree.insert(14);
  tree.insert(setOneValues);

  printTree(&tree);

  tree.remove(setTwoValues);

  printTree(&tree);

  system("pause");

  return 0;
}

void printTree(my_library::binary_search_tree<int>* tree) {
  tree->displayPreOrder();
  std::cout << "\n";
  tree->displayInOrder();
  std::cout << "\n";
  tree->displayPostOrder();
  std::cout << "\n";
}