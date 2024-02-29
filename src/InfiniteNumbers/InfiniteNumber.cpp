//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include <map>
#include "InfiniteNumber.h"
#include "Error.h"

namespace Operations {

    std::string InfiniteNumber::addition(std::string const &a, std::string const &b) {
        const int result = std::stoi( a ) + std::stoi( b );
        return std::to_string(result);
    }

    std::string InfiniteNumber::substraction(std::string const &a, std::string const &b) {
        const int result = std::stoi( a ) - std::stoi( b );
        return std::to_string(result);
    }

    std::string InfiniteNumber::division(std::string const &a, std::string const &b) {
        if (b == "0")
            throw ErrorCalculator::Error(ErrorCalculator::Error::DIVISION_BY_0);
        const int result = std::stoi( a ) / std::stoi( b );
        return std::to_string(result);
    }

    std::string InfiniteNumber::modulo(std::string const &a, std::string const &b) {
        if (b == "0")
            throw ErrorCalculator::Error(ErrorCalculator::Error::DIVISION_BY_0);
        const int result = std::stoi( a ) % std::stoi( b );
        return std::to_string(result);
    }

    std::string InfiniteNumber::multiplication(std::string const &a, std::string const &b) {
        const int result = std::stoi( a ) * std::stoi( b );
        return std::to_string(result);
    }

    std::string InfiniteNumber::makeOperation(std::string &operation) {
        std::string a;
        std::string b;
        std::string sign;

        for (unsigned int i = operation[0] == '+' || operation[0] == '-' ? 1 : 0; i < operation.size(); ++i) {
            if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == '/' || operation[i] == '%') {
                a = operation.substr(0, i);
                b = operation.substr(i + 1, operation.size() - 1);
                sign = operation.substr(i, 1);
                break;
            }
        }
        auto it = this->_operationMap.find(sign);
        if (it != this->_operationMap.end()) {
            OperationFunction func = it->second;
            return (func)(a, b);
        }
        throw ErrorCalculator::Error("Unknown operator");
    }

}
