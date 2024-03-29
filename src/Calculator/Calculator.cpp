//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include <iostream>
#include "Calculator.h"
#include "IOperations.hpp"
#include "ProxyOperationsPriorities.h"
#include "Error.h"

namespace Calculator {

    Calculator::Calculator() {
        description();
    }

    Calculator::~Calculator() = default;

    void Calculator::description() {
        std::cout << "The calculator can handle:" << std::endl << std::endl;
        std::cout << "\taddition: +" << std::endl;
        std::cout << "\tsubstraction: -" << std::endl;
        std::cout << "\tmultiplication: *" << std::endl;
        std::cout << "\tdivision: /" << std::endl;
        std::cout << "\tmodulo: % (rest of the division)" << std::endl;
        std::cout << std::endl << "you can enter your calcul the following way:" << std::endl;
        std::cout << std::endl << "\t(10 + 20) * 5" << std::endl << std::endl;
    }

    void Calculator::run() {
        std::string input;
        std::unique_ptr<Operations::IOperations> operations = std::make_unique<Operations::ProxyOperationsPriorities>();

        prompt();
        while (std::getline(std::cin, input)) {
            if (input.empty() || input == "exit") {
                std::cout << "Input terminated." << std::endl;
                break;
            }
            if (!this->_previousResults.count(input)) {
                try {
                    this->_previousResults[input] = operations->makeOperation(input);
                } catch (ErrorCalculator::Error &e) {
                    std::cout << e.what() << std::endl;
                }
            }
            std::cout << this->_previousResults[input] << std::endl << std::endl;;
            prompt();
        }
    }

    void Calculator::prompt() {
        std::cout << "[calcul] => ";
    }

}  // Calculator