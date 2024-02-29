//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include "Error.h"

namespace ErrorCalculator {

    Error::Error(std::string const &msg) {
        this->_errorMsg = msg;
        this->_error = ErrorType::CUSTOM;
    }

    Error::Error(ErrorType const &type) {
        this->_error = type;
    }

    const char *Error::what() const noexcept {
        if (this->_error == ErrorType::CUSTOM)
            return this->_errorMsg.c_str();
        if (this->_error == ErrorType::DIVISION_BY_0)
            return "Division by 0";
        if (this->_error == ErrorType::TYPO_USER_INPUT)
            return "Typo in user input";
        return "Unknow error";
    }

} // ErrorCalculator