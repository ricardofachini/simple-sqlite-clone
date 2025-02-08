#include <iostream>
#include "main.h"

#include <cstring>

int main(int argc, char* argv[]) {
    std::cout << "Iniciando very light sqlite!" << std::endl;

    InputBuffer* input_buffer = create_input_buffer();
    while (1) {
        read_input(input_buffer);

        if (strcmp(input_buffer->buffer, "!exit") == 0) {
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else {
            printf("Unrecognized command '%s'.\n", input_buffer->buffer);
        }
    }
    std::cout << "Finalizou" << std::endl;
    return 0;
}


