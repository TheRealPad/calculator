#include <Error.h>
#include <gtest/gtest.h>
#include "ProxyOperationsPriorities.h"

TEST(ProxyOperationsPriorities, ValidStringOne)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "()";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, true);
}

TEST(ProxyOperationsPriorities, ValidStringTwo)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "(1)";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, true);
}

TEST(ProxyOperationsPriorities, ValidStringThree)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "(1 + 1)";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, true);
}

TEST(ProxyOperationsPriorities, ValidStringFour)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "(1+1)-4 + (1 * 23456)";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, true);
}

TEST(ProxyOperationsPriorities, ValidStringFive)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "(((1 + 4) * 3) / 2) % 1";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, true);
}

TEST(ProxyOperationsPriorities, ValidStringSix)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "(((1 + 4) * 3) / 2) % (1 +3+((3% 4) + 4))";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, true);
}

TEST(ProxyOperationsPriorities, InvalidStringOne)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "invalid content";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, false);
}

TEST(ProxyOperationsPriorities, InvalidStringTwo)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "1 + a";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, false);
}

TEST(ProxyOperationsPriorities, InvalidStringThree)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "(";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, false);
}

TEST(ProxyOperationsPriorities, InvalidStringFour)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = ")";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, false);
}

TEST(ProxyOperationsPriorities, InvalidStringFive)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "(1 + 3";
    bool isValid = true;

    try {
        operations->makeOperation(str);
    } catch (ErrorCalculator::Error &e) {
        isValid = false;
    }
    EXPECT_EQ(isValid, false);
}