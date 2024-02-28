#include <gtest/gtest.h>
#include "Error.h"

TEST(Error, ThrowDivisionError)
{
    bool result = false;

    try {
        throw ErrorCalculator::Error(ErrorCalculator::Error::DIVISION_BY_0);
    } catch (ErrorCalculator::Error &e) {
        result = true;
    }
    EXPECT_EQ(result, true);
}

TEST(Error, DontThrowDivisionError)
{
    bool result = false;

    try {
    } catch (ErrorCalculator::Error &e) {
        result = true;
    }
    EXPECT_EQ(result, false);
}

TEST(Error, ThrowCustomError)
{
    bool result = false;

    try {
        throw ErrorCalculator::Error("Hello there");
    } catch (ErrorCalculator::Error &e) {
        result = true;
    }
    EXPECT_EQ(result, true);
}
