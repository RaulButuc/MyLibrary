/**
*  Is.cpp
*
*  @author Raul Butuc
*/

#include "stdafx.h"
#include "Is.h"

using namespace my_library;

auto Is::LessThan(long expectedValue) -> std::pair<char, long> {
  return std::make_pair('<', expectedValue);
}

auto Is::EqualTo(long expectedValue) -> std::pair<char, long> {
  return std::make_pair('=', expectedValue);
}

auto Is::GreaterThan(long expectedValue) -> std::pair<char, long> {
  return std::make_pair('>', expectedValue);
}

auto Is::EqualTo(std::string expectedValue) -> std::pair<char, std::string> {
  return std::make_pair('=', expectedValue);
}
