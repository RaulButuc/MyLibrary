/**
*  Assert.cpp
*
*  @author Raul Butuc
*/

#include "stdafx.h"
#include "Assert.h"

using namespace my_library;

auto Assert::That(bool actualValue, bool expectedValue) -> void {
  if (actualValue != expectedValue) {
    std::cout << "Error: Actual value does not match the expected value.\n" <<
      "    " << actualValue << " != " << expectedValue;
  }
}

auto Assert::That(long actualValue, std::pair<char, long> expected) -> void {
  char expectedOperation = expected.first;
  long expectedValue = expected.second;

  switch (expectedOperation) {
    case '<':
      if (actualValue >= expectedValue) {
        std::cout << "Error: Actual value is greater than or equal to the expected value.\n" <<
          "    " << actualValue << " >= " << expectedValue;
      }
      break;

    case '=':
      if (actualValue != expectedValue) {
        std::cout << "Error: Actual value does not match the expected value.\n" <<
          "    " << actualValue << " != " << expectedValue;
      }
      break;

    case '>':
      if (actualValue <= expectedValue) {
        std::cout << "Error: Actual value is less than or equal to the expected value.\n" <<
          "    " << actualValue << " <= " << expectedValue;
      }
      break;

    default:
      break;
  }
}

auto Assert::That(std::string actualValue, std::pair<char, std::string> expected) -> void {
  char expectedOperation = expected.first;
  std::string expectedValue = expected.second;

  switch (expectedOperation) {
    case '=':
      if (actualValue != expectedValue) {
        std::cout << "Error: Actual value does not match the expected value.\n" <<
          "    " << actualValue << " != " << expectedValue;
      }
      break;

    default:
      break;
  }
}
