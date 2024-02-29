#include <gtest/gtest.h>
#include "InfiniteNumber.h"

TEST(InfiniteNumber, AdditionOne)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "9+3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "12");
}

TEST(InfiniteNumber, AdditionTwo)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "-7+3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "-4");
}

TEST(InfiniteNumber, AdditionThree)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "-7+-3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "-10");
}

TEST(InfiniteNumber, SubstractionOne)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "9-3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "6");
}

TEST(InfiniteNumber, SubstractionTwo)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "-7-3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "-10");
}

TEST(InfiniteNumber, SubstractionThree)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "-7--3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "-4");
}

TEST(InfiniteNumber, MultiplicationOne)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "9*3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "27");
}

TEST(InfiniteNumber, MultiplicationTwo)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "-7*3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "-21");
}

TEST(InfiniteNumber, MultiplicationThree)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "-7*-3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "21");
}

TEST(InfiniteNumber, DivisionOne)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "9/3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "3");
}

TEST(InfiniteNumber, DivisionTwo)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "-7/3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "-2");
}

TEST(InfiniteNumber, DivisionThree)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "-7/-3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "2");
}

TEST(InfiniteNumber, RestOne)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "9%3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "0");
}

TEST(InfiniteNumber, RestTwo)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "-7%3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "-1");
}

TEST(InfiniteNumber, RestThree)
{
    std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
    std::string str = "-7%-3";
    EXPECT_EQ(infiniteNumber->makeOperation(str), "-1");
}
