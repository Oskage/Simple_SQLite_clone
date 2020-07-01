#ifndef SIMPLE_SQLITE_CLONE_STATEMENT_H
#define SIMPLE_SQLITE_CLONE_STATEMENT_H


#include <iostream>
#include <string>

#include "Enums.h"

class Statement {
private:
    StatementType type;
public:
    Statement() = default;

    PreparationState prepare(const std::string &input_line);
    void execute();
};


#endif //SIMPLE_SQLITE_CLONE_STATEMENT_H
