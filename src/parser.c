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
        AST_T *ast = parse_instruction(parser);
        printf("%d , %s , %s\n", ast->type, ast->name, ast->value);
        parser_continue(parser);
    }
}

// Parser Additions //

// Definition instruction: (statement: (assignment | functionCall) ";") | (ifBlock)
AST_T *parse_instruction(parser_T *parser)
{
    AST_T *ast = calloc(1, sizeof(struct AST_STRUCT));

    // Statement
    if (parser_try(parser, TOKEN_ID) == 0)
    {
        ast = init_ast(AST_ASSIGNMENT);
        ast->name = parser_eat(parser, TOKEN_ID)->value;
        parser_eat(parser, TOKEN_EQUALS);
        ast->value = parser_eat(parser, TOKEN_INT)->value;
        parser_eat(parser, TOKEN_SEMICOLON);
    }

    return ast;
}

// Parser Utils //

token_T *parser_eat(parser_T *parser, int type)
{
    if (parser->token->type != type)
    {
        printf("[Parser]: Unexpected token: `%s`, was expecting: `%s`\n", token_to_str(parser->token), token_type_to_str(type));
        exit(1);
    }

    token_T *token = parser->token;

    parser->token = lexer_next_token(parser->lexer);
    return token;
}

int parser_try(parser_T *parser, int type)
{
    if (parser->token->type != type)
    {
        return 1;
    }

    return 0;
}

token_T *parser_continue(parser_T *parser)
{
    parser->token = lexer_next_token(parser->lexer);
    return parser->token;
}