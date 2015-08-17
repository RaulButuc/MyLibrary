/**
 *  UnitTest.h
 *
 *  @author Raul Butuc.
 *  @version 1.0.0 16/08/2015
 */

#pragma once

#include <string>
#include "stdafx.h"

#ifdef UNITTEST_EXPORTS
#define UNITTEST_API __declspec(dllexport)
#else
#define UNITTEST_API __declspec(dllimport)
#endif

class UNITTEST_API UnitTest {

  public:
    UnitTest();
    static bool EXPECT_LT(long, long);
    static bool EXPECT_LT_OR_EQ(long, long);
    static bool EXPECT_EQ(long, long);
    static bool EXPECT_EQ_STR(std::string, std::string);
    static bool EXPECT_GT(long, long);
    static bool EXPECT_GT_OR_EQ(long, long);
    static bool EXPECT_NE(long, long);
    static bool EXPECT_NE_STR(std::string, std::string);
    ~UnitTest();

};
