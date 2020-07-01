#include "Statement.h"

//
// Other methods
//

PreparationState Statement::prepare(const std::string &input_line) {
    // Insert statement
    if(input_line.compare(0, 6, "insert") == 0) {
        type = StatementType::STATEMENT_INSERT;
        return PreparationState::PREPARE_SUCCESS;
    }

    // Select statement
    if(input_line.compare(0, 6, "select") == 0) {
        type = StatementType::STATEMENT_SELECT;
        return PreparationState::PREPARE_SUCCESS;
    }

    // Unrecognized statement
    return PreparationState::PREPARE_UNRECOGNIZED_STATEMENT;
}

void Statement::execute() {
    switch(type) {
        case (StatementType::STATEMENT_INSERT):
            std::cout << "some insert logic here" << std::endl;
            break;
        case (StatementType::STATEMENT_SELECT):
            std::cout << "some select logic here" << std::endl;
            break;
    }
}
