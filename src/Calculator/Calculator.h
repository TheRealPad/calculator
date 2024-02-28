//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <map>

namespace Calculator {

    class Calculator {

        public:
            Calculator();
            ~Calculator();
            bool run();
            static void description();

        private:
            void handleInput();
            static void prompt();

            std::map<std::string, std::string> _previousResults;

    };

} // Calculator

#endif //CALCULATOR_H
