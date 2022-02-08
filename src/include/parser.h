#ifndef LEMON_PARSER_H
#define LEMON_PARSER_H

#include "lexer.h"

typedef struct PARSER_STRUCT
{
    lexer_T *lexer;
} parser_T;

parser_T *init_parser(lexer_T *lexer);

void parser_parse(parser_T *parser);

#endif // LEMON_PARSER_H