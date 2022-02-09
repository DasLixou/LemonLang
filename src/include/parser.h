#ifndef LEMON_PARSER_H
#define LEMON_PARSER_H

#include "lexer.h"
#include "AST.h"
#include "list.h"

typedef struct PARSER_STRUCT
{
    lexer_T *lexer;
    token_T *token;
} parser_T;

parser_T *init_parser(lexer_T *lexer);

void parser_parse(parser_T *parser);

// Parser Additions //
AST_T *parse_instruction(parser_T *parser);
list_T *parse_block(parser_T *parser);

// Parser Utils //
token_T *parser_eat(parser_T *parser, int type);
int parser_try(parser_T *parser, int type);
token_T *parser_continue(parser_T *parser);

#endif // LEMON_PARSER_H