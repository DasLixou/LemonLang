#include "include/parser.h"

parser_T *init_parser(lexer_T *lexer)
{
    parser_T *parser = calloc(1, sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->token = lexer_next_token(parser->lexer);

    return parser;
}

AST_T *parser_parse(parser_T *parser)
{
    AST_T *ast = init_ast(AST_NOOP);
    while (parser->token->type != TOKEN_EOF)
    {
        list_push(ast->value, parse_instruction(parser));
    }
    return ast;
}

// Parser Additions //

// Definition instruction: (statement: (assignment | functionCall) ";") | (functionDeclaration | ifBlock)
AST_T *parse_instruction(parser_T *parser)
{
    AST_T *ast = calloc(1, sizeof(struct AST_STRUCT));

    // Statement
    if (parser_try(parser, TOKEN_KW_PUBLIC) == 0)
    {
        parser_eat(parser, TOKEN_KW_PUBLIC);
        ast = init_ast(AST_ASSIGNMENT);
        ast->name = parser_eat(parser, TOKEN_ID)->value;
        parser_eat(parser, TOKEN_EQUALS);
        ast->value = parser_eat(parser, TOKEN_INT)->value;
        parser_eat(parser, TOKEN_SEMICOLON);
    }
    else if (parser_try(parser, TOKEN_KW_FUNC) == 0)
    {
        parser_eat(parser, TOKEN_KW_FUNC);
        ast = init_ast(AST_FUNCTION_DECLARATION);
        ast->name = parser_eat(parser, TOKEN_ID)->value;
        parser_eat(parser, TOKEN_LPAREN);
        // TODO: Read parameters
        parser_eat(parser, TOKEN_RPAREN);
        ast->value = parse_block(parser);
    }
    else
    {
        printf("[Parser]: Didn't expect token %s in parsing instruction", token_to_str(parser->token));
        exit(1);
    }

    return ast;
}

list_T *parse_block(parser_T *parser)
{
    parser_eat(parser, TOKEN_LBRACE);
    list_T *nodes = init_list(sizeof(struct AST_STRUCT *));
    while (parser_try(parser, TOKEN_RBRACE) != 0)
    {
        list_push(nodes, parse_instruction(parser));
    }
    parser_eat(parser, TOKEN_RBRACE);
    return nodes;
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