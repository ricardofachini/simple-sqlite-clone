//
// Created by ricardofachini on 09/02/25.
//

#ifndef BUFFER_H
#define BUFFER_H

#include <cstdlib>

typedef  struct {
    int id;
    char* buffer;
    size_t size;
    ssize_t input_lenght;
} InputBuffer;

InputBuffer* create_input_buffer() {
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->size = 0;
    input_buffer->input_lenght = 0;

    return input_buffer;
}

void read_input(InputBuffer* input_buffer) {
    ssize_t bytes_read =
      getline(&(input_buffer->buffer), &(input_buffer->size), stdin);

    if (bytes_read <= 0) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }

    // Ignore trailing newline
    input_buffer->size = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
}

void close_input_buffer(InputBuffer* input_buffer) {
    delete input_buffer->buffer;
    delete input_buffer;
}

#endif //BUFFER_H
