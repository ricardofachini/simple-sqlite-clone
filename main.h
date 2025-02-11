//
// Created by ricardofachini on 18/01/25.
//

#ifndef MAIN_H
#define MAIN_H
#include <cstdlib>

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
  } MetaCommandResult;

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;

typedef enum {STATEMENT_INSERT, STATEMENT_SELECT, STATEMENT_DELETE, STATEMENT_UPDATE} SelectStatement;

typedef struct {
    SelectStatement type;
} Statement;





#endif //MAIN_H
