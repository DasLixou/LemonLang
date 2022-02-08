#ifndef LEMON_PARSER_H
#define LEMON_PARSER_H

#include "lexer.h"

typedef struct PARSER_STRUCT
{
    lexer_T *lexer;
} parser_T;

parser_T *init_parser(lexer_T *lexer);

#endif // LEMON_PARSER_H