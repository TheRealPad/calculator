//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#ifndef PROXYOPERATIONSPRIORITIES_H
#define PROXYOPERATIONSPRIORITIES_H

#include <memory>
#include "OperationsPriorities.h"

namespace Operations {

    class ProxyOperationsPriorities : public IOperations {

        public:
            ProxyOperationsPriorities();
            std::string makeOperation(std::string &operation) override;

        private:
            bool checkParenthesis(std::string const &operation);

            std::unique_ptr<OperationsPriorities> _operationsPriorities;
    };

} // Operations



#endif //PROXYOPERATIONSPRIORITIES_H
