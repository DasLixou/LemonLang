#include "include/parser.h"

parser_T *init_parser(lexer_T *lexer)
{
    parser_T *parser = calloc(1, sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->token = lexer_next_token(parser->lexer);

    return parser;
}

void parser_parse(parser_T *parser)
{
    while (parser->token->type != TOKEN_EOF)
    {
        printf("%s\n", token_to_str(parser->token));
        parse_statement(parser);
        parser_continue(parser);
    }
}

// Parser Additions //

void parse_statement(parser_T *parser)
{
}

// Parser Utils //

token_T *parser_eat(parser_T *parser, int type)
{
    if (parser->token->type != type)
    {
        printf("[Parser]: Unexpected token: `%s`, was expecting: `%s`\n", token_to_str(parser->token), token_type_to_str(type));
        exit(1);
    }

    parser->token = lexer_next_token(parser->lexer);
    return parser->token;
}

token_T *parser_continue(parser_T *parser)
{
    parser->token = lexer_next_token(parser->lexer);
    return parser->token;
}