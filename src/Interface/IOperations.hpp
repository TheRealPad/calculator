//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#ifndef IOPERATIONS_HPP
#define IOPERATIONS_HPP

#include <string>

namespace Operations {

    class IOperations {

        public:
            virtual ~IOperations() = default;
            virtual std::string makeOperation(std::string &operation) = 0;

    };

} // Operations

#endif //IOPERATIONS_HPP
