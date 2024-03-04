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
    EXPECT_EQ(isValid, false);
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
    EXPECT_EQ(isValid, true);
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

TEST(ProxyOperationsPriorities, OperatorPriorityOne)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "1+10*2";
    const std::string result = operations->makeOperation(str);

    EXPECT_EQ(result, "21");
}

TEST(ProxyOperationsPriorities, OperatorPriorityTwo)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "(1+10)*2";
    const std::string result = operations->makeOperation(str);

    EXPECT_EQ(result, "22");
}

TEST(ProxyOperationsPriorities, OperatorPriorityThree)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "((1+2)-4)*(5/(2+3))+3";
    const std::string result = operations->makeOperation(str);

    EXPECT_EQ(result, "2");
}

TEST(ProxyOperationsPriorities, NegativeNumbersOne)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "-1+1";
    const std::string result = operations->makeOperation(str);

    EXPECT_EQ(result, "0");
}

TEST(ProxyOperationsPriorities, NegativeNumbersTwo)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "1+-1";
    const std::string result = operations->makeOperation(str);

    EXPECT_EQ(result, "0");
}

TEST(ProxyOperationsPriorities, NegativeNumbersThree)
{
    std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();
    std::string str = "1--1";
    const std::string result = operations->makeOperation(str);

    EXPECT_EQ(result, "2");
}