//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#ifndef INFINITENUMBER_H
#define INFINITENUMBER_H

#include <IOperations.hpp>

namespace Operations {

    class InfiniteNumber : public IOperations {
        public:
            std::string makeOperation(std::string &operation);

        private:
            std::string addition(std::string &a, std::string &b);
            std::string substraction(std::string &a, std::string &b);
            std::string multiplication(std::string &a, std::string &b);
            std::string division(std::string &a, std::string &b);
            std::string modulo(std::string &a, std::string &b);
    };

} // Operation



#endif //INFINITENUMBER_H
