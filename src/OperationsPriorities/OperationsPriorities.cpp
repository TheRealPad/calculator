//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include <memory>
#include "OperationsPriorities.h"
#include "InfiniteNumber.h"

namespace Operations {

    std::string OperationsPriorities::makeOperation(std::string &operation) {
        std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
        std::string str = "-45671+245678";
        return infiniteNumber->makeOperation(str);
    }

}
