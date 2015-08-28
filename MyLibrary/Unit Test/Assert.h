/**
*  Assert.h
*
*  @author Raul Butuc.
*  @version 1.0.1 28/08/2015
*/

#pragma once

#include "stdafx.h"

#ifdef UNITTEST_EXPORTS
#define UNITTEST_API __declspec(dllexport)
#else
#define UNITTEST_API __declspec(dllimport)
#endif

namespace my_library {
    
    class UNITTEST_API Assert {

        public:
            static void That(bool, bool);
            static void That(long, std::pair<char, long>);
            static void That(std::string, std::pair<char, std::string>);

    };

}
