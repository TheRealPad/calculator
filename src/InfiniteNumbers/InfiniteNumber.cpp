//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include "InfiniteNumber.h"

#include <iostream>
#include <map>

namespace Operations {

    std::string InfiniteNumber::addition(std::string &a, std::string &b) {
        return "";
    }

    std::string InfiniteNumber::substraction(std::string &a, std::string &b) {
        return "";
    }

    std::string InfiniteNumber::division(std::string &a, std::string &b) {
        return "";
    }

    std::string InfiniteNumber::modulo(std::string &a, std::string &b) {
        return "";
    }

    std::string InfiniteNumber::multiplication(std::string &a, std::string &b) {
        return "";
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
        return this->addition(a, b);
    }

}
