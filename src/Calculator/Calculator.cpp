//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include <iostream>
#include "Calculator.h"
#include "Error.h"

namespace Calculator {
    // stocker les calculs et leur résultat
    Calculator::Calculator() {
        Calculator::Calculator::description();
    }

    Calculator::~Calculator() = default;

    void Calculator::description() {
        std::cout << "This is the class Calculator" << std::endl;
    }

    bool Calculator::run() {
        try {
            // throw ErrorCalculator::Error(ErrorCalculator::Error::DIVISION_BY_0);
        } catch (ErrorCalculator::Error &e) {
            std::cout << e.what() << std::endl;
            return false;
        }
        return true;
    }

}  // Calculator