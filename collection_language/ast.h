#ifndef LANGUAGE_AST_H
#define LANGUAGE_AST_H

#include <iostream>

struct Statement
{
    std::string value;
    std::vector<std::string> params;
};

typedef std::list<Statement> StatementList;

void printAST(const StatementList& statementList)
{
    for (auto e : statementList) {
        std::cout << e.value << "\t";
        for (auto p : e.params) {
            std::cout << p;
        }
        std::cout << std::endl;
    }
}


#endif
