#include "include/parser.h"

parser_T *init_parser(lexer_T *lexer)
{
    parser_T *parser = calloc(1, sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;

    return parser;
}

void parser_parse(parser_T *parser)
{
    token_T *token = calloc(1, sizeof(struct TOKEN_STRUCT));
    while ((token = lexer_next_token(parser->lexer))->type != TOKEN_EOF)
    {
        printf("%s\n", token_to_str(token));
    }
}