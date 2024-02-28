//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include "ProxyOperationsPriorities.h"

namespace Operations {

    ProxyOperationsPriorities::ProxyOperationsPriorities() {
        this->_operationsPriorities = std::make_unique<OperationsPriorities>();
    }

    std::string ProxyOperationsPriorities::makeOperation(std::string &operation) {
        return this->_operationsPriorities->makeOperation(operation);
    }


}
