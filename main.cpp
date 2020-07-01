#include <iostream>
#include <string> // getline()

#include "Enums.h"
#include "Statement.h"

MetaCommandResult do_meta_command(std::string &input_line) {
    if(input_line == ".exit") {
        input_line.clear();
        exit(EXIT_SUCCESS);
    } else {
        return MetaCommandResult::META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

void read_input_line(std::string &input_line) {
    std::getline(std::cin, input_line);

    if(input_line.length() < 0) {
        std::cout << "Error reading input" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    std::string input_line {};

    while(true) {
        while(input_line.length() == 0) {
            std::cout << "db > ";
            read_input_line(input_line);
        }

        if(input_line[0] == '.') {
            switch (do_meta_command(input_line)) {
                case (MetaCommandResult::META_COMMAND_SUCCESS):
                    continue;
                case (MetaCommandResult::META_COMMAND_UNRECOGNIZED_COMMAND):
                    std::cout << "Unrecognized command '" << input_line << "'." << std::endl;
                    input_line.clear();
                    continue;
            }
        }

        Statement statement{};
        switch(statement.prepare(input_line)) {
            case (PreparationState::PREPARE_SUCCESS):
                break;
            case (PreparationState::PREPARE_UNRECOGNIZED_STATEMENT):
                std::cout << "Unrecognized keyword at start of '" << input_line << "'." << std::endl;
                input_line.clear();
                continue;
        }

        statement.execute();
        std::cout << "executed" << std::endl;
        input_line.clear();
    }
}