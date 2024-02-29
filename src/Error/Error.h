//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <string>

namespace ErrorCalculator {

    class Error : public std::exception {

        public:

            enum ErrorType {
                CUSTOM,
                DIVISION_BY_0,
                TYPO_USER_INPUT
            };
            Error() = default;
            ~Error() override = default;
            explicit Error(std::string const &msg);
            explicit Error(ErrorType const &type);

            const char *what() const noexcept override;

        private:
            ErrorType _error;
            std::string _errorMsg;

    };

} // ErrorCalculator

#endif //ERROR_H
