//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include <memory>
#include <vector>
#include <algorithm>
#include "OperationsPriorities.h"
#include "Error.h"
#include "InfiniteNumber.h"

namespace Operations {

   std::string OperationsPriorities::operatorPriorities(std::vector<std::string> &blocks, std::vector<std::string> &operators) {
       std::unique_ptr<IOperations> infiniteNumber = std::make_unique<InfiniteNumber>();
       std::string finalResult;

       for (auto c : {"*", "/", "%", "+", "-"}) {
           if (std::count(operators.begin(), operators.end(), c)) {
               for (unsigned int i = 0; i < operators.size(); ++i) {
                   std::string str = blocks[i] + operators[i] + blocks[i + 1];
                   if (operators[i] == c) {
                       const std::string result = infiniteNumber->makeOperation(str);
                       blocks[i] = result;
                       blocks[i + 1] = result;
                       finalResult = result;
                   }
               }
           }
       }
       return finalResult;
   }

    // gérer nombre négatif
    std::string OperationsPriorities::createBlock(std::string &block) {
        std::vector<std::string> blocks;
        std::vector<std::string> operators;
        unsigned int nbrParenthesis = 0;
        bool inParenthesis = false;

        for (int i = 0; i < block.size() ; ++i) {
            if ((block[i] == '+' || block[i] == '-' || block[i] == '*' || block[i] == '/' || block[i] == '%') && !inParenthesis) {
                std::string s(1, block[i]);
                operators.push_back(s);
                if (!block.substr(0, i).empty())
                    blocks.push_back(block.substr(0, i));
                block.erase(0, i + 1);
                i = -1;
            }
            if (block[i] == '(') {
                inParenthesis = true;
                ++nbrParenthesis;
            }
            if (block[i] == ')' && nbrParenthesis == 1) {
                inParenthesis = false;
                nbrParenthesis = 0;
                if (!block.substr(0, i + 1).empty())
                    blocks.push_back(block.substr(0, i + 1));
                block.erase(0, i + 1);
                i = -1;
            }
            if (block[i] == ')' && nbrParenthesis > 1) {
                --nbrParenthesis;
            }
        }
        if (!block.empty())
            blocks.push_back(block);
        if (operators.size() != blocks.size() - 1)
            throw ErrorCalculator::Error(ErrorCalculator::Error::TYPO_USER_INPUT);
        for (auto &b : blocks) {
            if (b[0] == '(') {
                std::string tmp = b.substr(1, b.size() - 2);
                if (!this->_previousResults.count(tmp))
                    this->_previousResults[tmp] = this->createBlock(tmp);
                b = this->_previousResults[tmp];
            }
        }
        return this->operatorPriorities(blocks, operators);
    }

    std::string OperationsPriorities::makeOperation(std::string &operation) {
        operation.erase(remove_if(operation.begin(), operation.end(), isspace), operation.end());
        return this->createBlock(operation);
    }

}
