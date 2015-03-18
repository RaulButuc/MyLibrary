/**
 *  test_list.cpp
 *
 *  @author Raul Butuc.
 *  @version 1.0.1 18/03/2015
 */

#include <iostream>
#include <algorithm>
#include "list.h"

using std::cout;
using std::find;
using namespace my_library;

int main(int argc, char* argv[]) {
  // Declare a new singly linked list with the first 5 elements initialised to 'y'.
  list<char> my_list(3, 'Y');

  // Check whether the list is or is not empty.
  cout << " o Checking the state of my_list: ";
  cout << "The list is" << (my_list.empty() ? "" : " not") << " empty" << "\n";

  // Add some characters to the list.
  for (char i = 'a'; i < 'z'; i += 2) {
    my_list.push_back(i);
  }
  
  // Get an iterator for the first element.
  list<char>::iterator it = my_list.begin();
  
  // Loop through the list and prove its mutability.
  cout << " o Printing the elements of my_list: ";
  for (; it != my_list.end(); ++it) {
    *it += 1;
    cout << *it << " ";
  }
  cout << "\n";

  // Take two values, one that exists in the list and one that doesn't.
  char first_value = 'x';
  char second_value = 'H';

  // Get an iterator to first_value, if found; then print out a message.
  it = find(my_list.begin(), my_list.end(), first_value);
  cout << " o Testing 'find' in my_list: ";
  cout << "Element " << first_value << (it != my_list.end() ? "" : " not") << " found!" << "\n";
  
  // Get an iterator to second_value, if found; then print out a message.
  it = find(my_list.begin(), my_list.end(), second_value);
  cout << " o Testing 'find' in my_list: ";
  cout << "Element " << second_value << (it != my_list.end() ? "" : " not") << " found!" << "\n";

  // Create a copy of the first list, by using a constructor which takes iterators as arguments.
  list<char> copy_my_list(my_list.begin(), my_list.end());

  // Get an iterator for the first element of the copy of the list and print the list out.
  list<char>::iterator copy_it = copy_my_list.begin();
  cout << " o Printing the elements of copy_my_list: ";
  for (; copy_it != copy_my_list.end(); ++copy_it) {
    cout << *copy_it << " ";
  }
  cout << "\n";

  // Create a constant copy of the first list, by using a constructor which takes a list as an arguement.
  const list<char> const_copy_my_list(my_list);

  // Get a const_iterator for the first element of the other copy of the list and print the list out.
  list<char>::const_iterator const_copy_it = const_copy_my_list.begin();
  cout << " o Printing the elements of const_copy_my_list: ";
  for (; const_copy_it != const_copy_my_list.end(); ++const_copy_it) {
    cout << *const_copy_it << " ";
  }
  cout << "\n";

  system("pause");
  return 0;
}