/**
 *  test_forward_list.cpp
 *
 *  @author Raul Butuc.
 *  @version 1.3.1 28/08/2015
 */

// Not yet updated to make use of the custom unit test framework.

#include <iostream>
#include <string>
#include "forward_list.h"
#include "Assert.h"
#include "Is.h"

using std::cout;
using std::find;
using std::string;
using my_library::forward_list;
using my_library::Assert;
using my_library::Is;

void test_forward_list_one();
void test_forward_list_two();
void test_forward_list_three();
void test_forward_list_four();

forward_list<char> addOne(const forward_list<char>&);

int main(int argc, char* argv[]) {
  
  test_forward_list_one();
  test_forward_list_two();
  test_forward_list_three();
  test_forward_list_four();

  system("pause");
  return 0;
}

void test_forward_list_one() {
  cout << "\n" << "----------------- TEST 1 -----------------" << "\n";

  cout << " - Create a new list (3, 'Y')" << "\n";
  forward_list<char> my_list(3, 'Y');

  forward_list<char>::iterator it = my_list.begin();
  cout << " o Printing the elements of my_list: ";
  for (; it != my_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  cout << " o Checking the state of my_list: ";
  cout << "The list is" << (my_list.empty() ? "" : " not") << " empty" << "\n";

  cout << " - Push in front the characters from 'a' to 'y' in steps of 2, then reverse the list" << "\n";
  for (char i = 'a'; i < 'z'; i += 2) {
    my_list.push_front(i);
  }
  my_list.reverse();

  it = my_list.begin();
  cout << " o Printing the elements of my_list: ";
  for (; it != my_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  char first_value = 'y';
  char second_value = 'H';

  it = find(my_list.begin(), my_list.end(), first_value);
  cout << " o Testing std::find in my_list: ";
  cout << "Element " << first_value << (it != my_list.end() ? "" : " not") << " found!" << "\n";

  it = find(my_list.begin(), my_list.end(), second_value);
  cout << " o Testing std::find in my_list: ";
  cout << "Element " << second_value << (it != my_list.end() ? "" : " not") << " found!" << "\n";
}

void test_forward_list_two() {
  cout << "\n" << "----------------- TEST 2 -----------------" << "\n";

  cout << " - Create a new empty list" << "\n";
  forward_list<char> my_list;

  cout << " o Checking the state of my_list: ";
  cout << "The list is" << (my_list.empty() ? "" : " not") << " empty" << "\n";

  cout << " - Assign the new list (5, '@')" << "\n";
  my_list.assign(5, '@');
 
  forward_list<char>::iterator it = my_list.begin();
  forward_list<char>::const_iterator cIt = my_list.cbegin();

  cout << " o Printing the elements of my_list (after assignment): ";
  for (; it != my_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  cout << " - Set the constant iterator to point 3 steps ahead from the beginning." << "\n";
  cIt += 3;
  
  cout << " - Insert after the current constant iterator position the 'w' char (by moving)" << "\n";
  my_list.insert_after(cIt, 'w');

  it = my_list.begin();
  cout << " o Printing the elements of my_list: ";
  for (; it != my_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  cout << " - Increment the constant iterator 1 step, then insert after it 3 times 'z' (++cIt, 3, 'z')" << "\n";
  my_list.insert_after(++cIt, 3, 'z');

  it = my_list.begin();
  cout << " o Printing the elements of my_list: ";
  for (; it != my_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  cout << " - Create a copy of my_list (copy_my_list) by passing the begin and end iterators" << "\n";
  forward_list<char> copy_my_list(my_list.begin(), my_list.end());

  forward_list<char>::iterator copyIt = copy_my_list.begin();
  cout << " o Printing the elements of copy_my_list: ";
  for (; copyIt != copy_my_list.end(); ++copyIt) {
    cout << *copyIt << " ";
  }
  cout << "\n";

  cout << " - Set a const_iterator to the 1st element and last element in the list" << "\n";
  forward_list<char>::const_iterator erasePosStart = copy_my_list.cbegin();
  forward_list<char>::const_iterator erasePosEnd = copy_my_list.cend();

  cout << " - Erase all the elements after the 1st one" << "\n";
  copy_my_list.erase_after(erasePosStart, erasePosEnd);

  copyIt = copy_my_list.begin();
  cout << " o Printing the elements of copy_my_list: ";
  for (; copyIt != copy_my_list.end(); ++copyIt) {
    cout << *copyIt << " ";
  }
  cout << "\n";
}

void test_forward_list_three() {
  cout << "\n" << "----------------- TEST 3 -----------------" << "\n";

  cout << " - Create a new list from a temporary list new_list(forward_list<string>(7, \"Abc\"));" << "\n";
  forward_list<string> new_list(forward_list<string>(7, "Abc"));

  forward_list<string>::iterator it = new_list.begin();
  cout << " o Printing the elements of new_list: ";
  for (; it != new_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  cout << " - Push front the string \"World!\"" << "\n";
  new_list.push_front("World!");

  it = new_list.begin();
  cout << " o Printing the elements of new_list: ";
  for (; it != new_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  cout << " - Push front the string \"Hello\"" << "\n";
  new_list.push_front("Hello");

  it = new_list.begin();
  cout << " o Printing the elements of new_list: ";
  for (; it != new_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  cout << " o Print the first element of new_list (using the front function): ";
  cout << new_list.front() << "\n";
  
  cout << " - Pop the first five elements" << "\n";
  new_list.pop_front();
  new_list.pop_front();
  new_list.pop_front();
  new_list.pop_front();
  new_list.pop_front();

  it = new_list.begin();
  cout << " o Printing the elements of new_list (after popping the first five): ";
  for (; it != new_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";
}

void test_forward_list_four() {
  cout << "\n" << "----------------- TEST 4 -----------------" << "\n";

  cout << " - Create a new list (empty)" << "\n";
  forward_list<char> my_list;

  cout << " - Push to front all the characters from 'a' to 'y' in steps of 4, then reverse" << "\n";
  for (char i = 'a'; i < 'z'; i += 4) {
    my_list.push_front(i);
  }
  my_list.reverse();

  forward_list<char>::iterator it = my_list.begin();
  cout << " o Print the elements of my_list: ";
  for (; it != my_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  cout << " - Create a new list (my_other_list) initialised with (55, '+')" << "\n";
  forward_list<char> my_other_list(55, '+');
    
  it = my_other_list.begin();
  cout << " o Print the elements of my_other_list: ";
  for (; it != my_other_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  cout << " - Copy the contets of my_list over my_other_list using the overloaded operator=" << "\n";
  my_other_list = my_list;

  it = my_other_list.begin();
  cout << " o Print the elements of my_other_list: ";
  for (; it != my_other_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  cout << " - Call a function that returns a new list (temporary by defininition) from a given one "
    << "(my_other_list) and assign it to my_list using the overloaded operator= for moving data" << "\n";
  my_list = addOne(my_other_list);

  it = my_list.begin();
  cout << " o Print the elements of my_list: ";
  for (; it != my_list.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";
}

forward_list<char> addOne(const forward_list<char>& _forward_list) {
  forward_list<char> result;
  
  forward_list<char>::const_iterator it = _forward_list.begin();
  for (; it != _forward_list.end(); ++it) {
    result.push_front((*it) + 1);
  }
  result.reverse();
  
  return result;
}
