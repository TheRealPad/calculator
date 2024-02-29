//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include <regex>
#include "ProxyOperationsPriorities.h"

#include <Error.h>

namespace Operations {

    ProxyOperationsPriorities::ProxyOperationsPriorities() {
        this->_operationsPriorities = std::make_unique<OperationsPriorities>();
    }

    bool ProxyOperationsPriorities::checkParenthesis(std::string const &operation) {
        unsigned int nbrLeftParenthesis = 0;

        for (auto const &c : operation) {
            if (c == '(')
                ++nbrLeftParenthesis;
            if (c == ')' && nbrLeftParenthesis == 0)
                return false;
            if (c == ')')
                --nbrLeftParenthesis;
        }
        return nbrLeftParenthesis == 0;
    }


    std::string ProxyOperationsPriorities::makeOperation(std::string &operation) {
        std::regex self_regex("^[0-9()+*/%\\- ]+$",std::regex_constants::ECMAScript | std::regex_constants::icase);
        if (!std::regex_search(operation, self_regex) || !this->checkParenthesis(operation))
            throw ErrorCalculator::Error(ErrorCalculator::Error::TYPO_USER_INPUT);
        return this->_operationsPriorities->makeOperation(operation);
    }


}
