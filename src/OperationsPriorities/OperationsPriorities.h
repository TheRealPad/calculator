//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#ifndef OPERATIONSPRIORITIES_H
#define OPERATIONSPRIORITIES_H

#include <iostream>
#include <map>
#include "IOperations.hpp"

namespace Operations {

    class OperationsPriorities : IOperations {

        public:
            OperationsPriorities() = default;
            ~OperationsPriorities() override = default;
            std::string makeOperation(std::string &operation) override;

        private:
            std::string createBlock(std::string &block);
            std::string operatorPriorities(std::vector<std::string> &blocks, std::vector<std::string> &operators);

            std::map<std::string, std::string> _previousResults;
    };

} // Operations

#endif //OPERATIONSPRIORITIES_H
