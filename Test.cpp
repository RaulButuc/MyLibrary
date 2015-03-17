/**
 *  Test.cpp
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 16/03/2015
 */

#include <iostream>
#include "list.h"

using std::cout;
using namespace my_library;

int main(int argc, char* argv[]) {
  list<short> my_list;

  if (my_list.empty()) {
    std::cout << "List is empty" << "\n";
  }

  for (int i = 0; i < 100; i += 10) {
    my_list.push_back(i);
  }

  list<short>::iterator it = my_list.begin();

  for (; it != my_list.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  system("pause");
  return 0;
}