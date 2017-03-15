/**
 *  Is.h
 *
 *  @author Raul Butuc
 */

#pragma once

#include <string>
#include "stdafx.h"

#ifdef UNITTEST_EXPORTS
#define UNITTEST_API __declspec(dllexport)
#else
#define UNITTEST_API __declspec(dllimport)
#endif

namespace my_library { 

  class UNITTEST_API Is {
    
    public:
      static auto LessThan(long) -> std::pair<char, long>;
      static auto EqualTo(long) -> std::pair<char, long>;
      static auto GreaterThan(long) -> std::pair<char, long>;
      static auto EqualTo(std::string) -> std::pair<char, std::string>;

      static const bool False = false;
      static const bool True = true;

  };

}
