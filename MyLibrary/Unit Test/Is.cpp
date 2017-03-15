/**
*  Is.cpp
*
*  @author Raul Butuc
*/

#include "stdafx.h"
#include "Is.h"

using namespace my_library;

std::pair<char, long> Is::LessThan(long expectedValue) {
  return std::make_pair('<', expectedValue);
}

std::pair<char, long> Is::EqualTo(long expectedValue) {
  return std::make_pair('=', expectedValue);
}

std::pair<char, long> Is::GreaterThan(long expectedValue) {
  return std::make_pair('>', expectedValue);
}

std::pair<char, std::string> Is::EqualTo(std::string expectedValue) {
  return std::make_pair('=', expectedValue);
}
