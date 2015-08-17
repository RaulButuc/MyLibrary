/**
*  UnitTest.cpp
*
*  @author Raul Butuc.
*  @version 1.0.0 16/08/2015
*/

#include "stdafx.h"
#include "UnitTest.h"

UnitTest::UnitTest() { }

bool UnitTest::EXPECT_LT(long testValue, long expectedValue) {
    return testValue < expectedValue;
}

bool UnitTest::EXPECT_LT_OR_EQ(long testValue, long expectedValue) {
    return testValue <= expectedValue;
}

bool UnitTest::EXPECT_EQ(long testValue, long expectedValue) {
    return testValue == expectedValue;
}

bool UnitTest::EXPECT_EQ_STR(std::string testValue, std::string expectedValue) {
    return testValue == expectedValue;
}

bool UnitTest::EXPECT_GT(long testValue, long expectedValue) {
    return testValue > expectedValue;
}

bool UnitTest::EXPECT_GT_OR_EQ(long testValue, long expectedValue) {
    return testValue >= expectedValue;
}

bool UnitTest::EXPECT_NE(long testValue, long expectedValue) {
    return testValue != expectedValue;
}

bool UnitTest::EXPECT_NE_STR(std::string testValue, std::string expectedValue) {
    return testValue != expectedValue;
}


UnitTest::~UnitTest() { }
