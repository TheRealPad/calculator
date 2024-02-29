//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#ifndef INFINITENUMBER_H
#define INFINITENUMBER_H

#include <map>
#include "IOperations.hpp"

namespace Operations {

    class InfiniteNumber : public IOperations {
        public:
            InfiniteNumber() = default;
            ~InfiniteNumber() override = default;
            std::string makeOperation(std::string &operation) override;

        private:
            static std::string addition(std::string const &a, std::string const &b);
            static std::string substraction(std::string const &a, std::string const &b);
            static std::string multiplication(std::string const &a, std::string const &b);
            static std::string division(std::string const &a, std::string const &b);
            static std::string modulo(std::string const &a, std::string const &b);

            using OperationFunction = std::string (*)(const std::string&, const std::string&);
            const std::map<std::string, OperationFunction> _operationMap = {
                {"+", &InfiniteNumber::addition},
                {"-", &InfiniteNumber::substraction},
                {"*", &InfiniteNumber::multiplication},
                {"/", &InfiniteNumber::division},
                {"%", &InfiniteNumber::modulo}
            };
    };

} // Operation



#endif //INFINITENUMBER_H
