/**
 *  test_forward_list.cpp
 *
 *  @author Raul Butuc.
 *  @version 1.1.2 24/03/2015
 */

#include <iostream>
#include <algorithm>
#include <string>
#include "forward_list.h"

using std::cout;
using std::find;
using std::string;
using namespace my_library;

int main(int argc, char* argv[]) {
  // Declare a new singly linked list with the first 5 elements initialised to 'Y'.
  forward_list<char> my_list(3, 'Y');

  // Check whether the list is or is not empty.
  cout << " o Checking the state of my_list: ";
  cout << "The list is" << (my_list.empty() ? "" : " not") << " empty" << "\n";

  // Add some characters to the list.
  for (char i = 'a'; i < 'z'; i += 2) {
    my_list.push_front(i);
  }

  // Reverse the list.
  my_list.reverse();
  
  // Get an iterator for the first element.
  forward_list<char>::iterator it = my_list.begin();
  
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
  forward_list<char> copy_my_list(my_list.begin(), my_list.end());

  // Get an iterator for the first element of the copy of the list and print the list out.
  forward_list<char>::iterator copy_it = copy_my_list.begin();
  cout << " o Printing the elements of copy_my_list: ";
  for (; copy_it != copy_my_list.end(); ++copy_it) {
    cout << *copy_it << " ";
  }
  cout << "\n";

  // Create a constant copy of the first list, by using a constructor which takes a list as an arguement.
  const forward_list<char> const_copy_my_list(my_list);

  // Get a const_iterator for the first element of the other copy of the list and print the list out.
  forward_list<char>::const_iterator const_copy_it = const_copy_my_list.begin();
  cout << " o Printing the elements of const_copy_my_list: ";
  for (; const_copy_it != const_copy_my_list.end(); ++const_copy_it) {
    cout << *const_copy_it << " ";
  }
  cout << "\n";

  // Create a new list using the move constructor, moving the temporary list into the new_list and then deallocating
  // the temporary memory used.
  forward_list<string> new_list(forward_list<string>(7, "Abc"));

  // Get an iterator for the first element of the new list and print the list out.
  forward_list<string>::iterator new_list_it = new_list.begin();
  cout << " o Printing the elements of new_list: ";
  for (; new_list_it != new_list.end(); ++new_list_it) {
    cout << *new_list_it << " ";
  }
  cout << "\n";

  // Pop the first two elements.
  new_list.pop_front();
  new_list.pop_front();

  // Get an iterator for the first element of the new list and print the list out.
  new_list_it = new_list.begin();
  cout << " o Printing the elements of new_list (after popping the first two): ";
  for (; new_list_it != new_list.end(); ++new_list_it) {
    cout << *new_list_it << " ";
  }
  cout << "\n";

  // Pop the first three elements in my_list.
  my_list.pop_front();
  my_list.pop_front();
  my_list.pop_front();

  // Get an iterator for the first element.
  it = my_list.begin();

  // Loop through the list and prove its mutability.
  cout << " o Printing the elements of my_list (after popping the first three): ";
  for (; it != my_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  // Get the first element of the first list and print it out.
  cout << " o Print the first element of my_list: ";
  cout << my_list.front() << "\n";
  
  // Create a new list.
  forward_list<char> my_other_list(55, '+');
  
  // Get an iterator for the first element of my_other_list and print the list out.
  it = my_other_list.begin();
  cout << " o Print the elements of my_other_list: ";
  for (; it != my_other_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  // Copy the contents from my_list into my_other_list
  my_other_list = my_list;

  // Get an iterator for the first element of my_other_list and print the list out.
  it = my_other_list.begin();
  cout << " o Print the elements of my_other_list (after copying my_list into it): ";
  for (; it != my_other_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  // Get an iterator for the first element of my_list and print the list out.
  it = my_list.begin();
  cout << " o Print the elements of my_list: ";
  for (; it != my_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  system("pause");
  return 0;
}