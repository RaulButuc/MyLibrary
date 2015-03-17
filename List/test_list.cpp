/**
 *  Test.cpp
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 16/03/2015
 */

#include <iostream>
#include <algorithm>
#include "list.h"

using std::cout;
using std::find;
using namespace my_library;

int main(int argc, char* argv[]) {
  list<short> my_list;

  if (my_list.empty()) {
    cout << "List is empty" << "\n";
  }

  for (int i = 0; i < 100; i += 10) {
    my_list.push_back(i);
  }

  list<short>::iterator it = my_list.begin();

  for (; it != my_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  short first_value = 50;
  short second_value = 23;

  it = find(my_list.begin(), my_list.end(), first_value);
  if (it != my_list.end()) {
    cout << "Element " << first_value << " found!" << "\n";
  }
  else {
    cout << "Element " << first_value << " not found!" << "\n";
  }

  it = find(my_list.begin(), my_list.end(), second_value);
  if (it != my_list.end()) {
    cout << "Element " << second_value << " found!" << "\n";
  }
  else {
    cout << "Element " << second_value << " not found!" << "\n";
  }

  system("pause");
  return 0;
}