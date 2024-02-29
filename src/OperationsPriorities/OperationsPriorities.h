//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#ifndef OPERATIONSPRIORITIES_H
#define OPERATIONSPRIORITIES_H

#include <iostream>
#include "IOperations.hpp"

namespace Operations {

    class OperationsPriorities : IOperations {

        public:
            OperationsPriorities() = default;
            ~OperationsPriorities() override = default;
            std::string makeOperation(std::string &operation) override;
    };

} // Operations

#endif //OPERATIONSPRIORITIES_H
