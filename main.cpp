#include "Calculator.h"

int main(int ac, char **ag)
{
    Calculator::Calculator calculator;

    return calculator.run() ? 0 : 1;
}
