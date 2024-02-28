//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include <iostream>
#include "Calculator.h"
#include "Error.h"

namespace Calculator {
    Calculator::Calculator() {
        Calculator::Calculator::description();
    }

    Calculator::~Calculator() = default;

    void Calculator::description() {
        std::cout << "This is the class Calculator" << std::endl;
    }

    bool Calculator::run() {
        try {
            Calculator::Calculator::handleInput();
        } catch (ErrorCalculator::Error &e) {
            std::cout << e.what() << std::endl;
            return false;
        }
        return true;
    }

    void Calculator::handleInput() {
        std::string input;

        Calculator::prompt();
        while (std::getline(std::cin, input)) {
            if (input.empty()) {
                std::cout << "Input terminated." << std::endl;
                break;
            }
            if (!this->_previousResults.count(input)) {
                // call calcul here
                this->_previousResults[input] = input;
            }
            std::cout << this->_previousResults[input] << std::endl << std::endl;;
            Calculator::prompt();
        }
    }

    void Calculator::prompt() {
        std::cout << "[calcul] => ";
    }



}  // Calculator