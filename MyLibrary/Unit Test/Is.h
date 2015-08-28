/**
 *  Is.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 21/08/2015
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
            static std::pair<char, long> LessThan(long);
            static std::pair<char, long> EqualTo(long);
            static std::pair<char, long> GreaterThan(long);
            static std::pair<char, std::string> EqualTo(std::string);

            static const bool False = false;
            static const bool True = true;

    };

}
