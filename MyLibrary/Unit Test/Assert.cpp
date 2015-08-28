/**
*  Assert.cpp
*
*  @author Raul Butuc.
*  @version 1.0.0 21/08/2015
*/

#include "stdafx.h"
#include "Assert.h"

using namespace my_library;

void Assert::That(bool actualValue, bool expectedValue) {
    if (actualValue != expectedValue) {
        std::cout << "Error: Actual value does not match the expected value.\n" <<
          "        " << actualValue << " != " << expectedValue;
    }
}

void Assert::That(long actualValue, std::pair<char, long> expected) {
    char expectedOperation = expected.first;
    long expectedValue = expected.second;

    switch (expectedOperation) {
        case '<':
            if (actualValue >= expectedValue) {
                std::cout << "Error: Actual value is greater than or equal to the expected value.\n" <<
                  "        " << actualValue << " >= " << expectedValue;
            }
            break;

        case '=':
            if (actualValue != expectedValue) {
                std::cout << "Error: Actual value does not match the expected value.\n" <<
                  "        " << actualValue << " != " << expectedValue;
            }
            break;

        case '>':
            if (actualValue <= expectedValue) {
                std::cout << "Error: Actual value is less than or equal to the expected value.\n" <<
                  "        " << actualValue << " <= " << expectedValue;
            }
            break;

        default:
            break;
    }
}

void Assert::That(std::string actualValue, std::pair<char, std::string> expected) {
    char expectedOperation = expected.first;
    std::string expectedValue = expected.second;

    switch (expectedOperation) {
        case '=':
            if (actualValue != expectedValue) {
                std::cout << "Error: Actual value does not match the expected value.\n" <<
                  "        " << actualValue << " != " << expectedValue;
            }
            break;

        default:
            break;
    }
}
