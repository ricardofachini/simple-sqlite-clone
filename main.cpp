#include <iostream>
#include "main.h"
#include "buffer.h"
#include "btree.h"

#include <cstring>

MetaCommandResult do_meta_command(InputBuffer* input_buffer) {
    if (strcmp(input_buffer->buffer, ".exit") == 0) {
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}
PrepareResult prepare_statement(InputBuffer* input_buffer,
                                Statement* statement) {
    if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (strcmp(input_buffer->buffer, "select") == 0) {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement* statement) {
    switch (statement->type) {
        case (STATEMENT_INSERT):
            std::cout << "vai fazer insert" << std::endl;
            break;
        case (STATEMENT_SELECT):
            std::cout << "vai fazer select" << std::endl;
            break;
    }
}

int main(int argc, char* argv[]) {
    std::cout << "Iniciando very light sqlite!" << std::endl;

    InputBuffer* input_buffer = create_input_buffer();
    while (1) {
        read_input(input_buffer);
        // se for meta-comando
        if (input_buffer->buffer[0] == '.') {
            switch (do_meta_command(input_buffer)) {
                case (META_COMMAND_SUCCESS):
                    continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                    std::cout << "Unrecognized command!" << std::endl;
                    continue;
            }
        }
        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
            case (PREPARE_SUCCESS):
                break;
            case (PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognized keyword at start of '%s'.\n",
                    input_buffer->buffer);
                continue;
            }
        execute_statement(&statement);
        printf("Executed.\n");
    }
    std::cout << "Finalizou" << std::endl;
    return 0;
}




