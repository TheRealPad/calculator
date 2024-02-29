//
// Created by Pierre-Alexandre Delgado on 28/02/2024.
//

#include <memory>
#include <vector>
#include "OperationsPriorities.h"
#include "InfiniteNumber.h"

namespace Operations {

    // modifie valeur du block
    // stock block dans la mémoire pour éviter d'aller plus loin si possible
    // priorité calcul
    std::string OperationsPriorities::createBlock(std::string &block) {
        std::vector<std::string> blocks;
        std::vector<std::string> operators;
        unsigned int nbrParenthesis = 0;
        bool inParenthesis = false;

        std::cout << block << std::endl;
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
        for (auto const &b : blocks) {
            if (b[0] == '(') {
                std::string pad = b.substr(1, b.size() - 2);
                this->createBlock(pad);
            }
            std::cout << b << std::endl;
        }
        for (auto const &b : operators) {
            std::cout << b << std::endl;
        }
        return {"1"};
    }

    /**
     * \brief divise en block le calcul avec soit nombre ou parenthese et si parenthese le résultat est un appel recusrsif sur la parenthèse
     * \param operation
     * \return
     */
    std::string OperationsPriorities::makeOperation(std::string &operation) {
        std::unique_ptr<Operations::IOperations> infiniteNumber = std::make_unique<Operations::InfiniteNumber>();
        // std::string str = "1 + (1 + 1)";
        std::string str = "((1+2)-4)*(5/(2+3))+3";
        str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
        this->createBlock(str);
        return infiniteNumber->makeOperation(operation);
    }

}
