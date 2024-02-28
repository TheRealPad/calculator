//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <map>
#include <string>

namespace Calculator {

    class Calculator {

        public:
            Calculator();
            ~Calculator();
            void run();
            static void description();

        private:
            static void prompt();

            std::map<std::string, std::string> _previousResults;

    };

} // Calculator

#endif //CALCULATOR_H
