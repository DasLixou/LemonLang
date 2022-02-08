#ifndef LEMON_PARSER_H
#define LEMON_PARSER_H

#include "lexer.h"

typedef struct PARSER_STRUCT
{
    lexer_T *lexer;
    token_T *token;
} parser_T;

parser_T *init_parser(lexer_T *lexer);

void parser_parse(parser_T *parser);

// Parser Additions //
void parse_statement(parser_T *parser);

// Parser Utils //
token_T *parser_eat(parser_T *parser, int type);
token_T *parser_continue(parser_T *parser);

#endif // LEMON_PARSER_H