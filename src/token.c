#include "include/token.h"

token_T *init_token(char *value, int type)
{
    token_T *token = calloc(1, sizeof(struct TOKEN_STRUCT));
    token->value = value;
    token->type = type;

    return token;
}

const char *token_type_to_str(int type)
{
    switch (type)
    {
    case TOKEN_ID:
        return "ID";
    case TOKEN_KW_PUBLIC:
        return "KEYWORD_PUBLIC";
    case TOKEN_EQUALS:
        return "EQUALS";
    case TOKEN_LPAREN:
        return "LPAREN";
    case TOKEN_RPAREN:
        return "RPAREN";
    case TOKEN_LBRACE:
        return "LBRACE";
    case TOKEN_RBRACE:
        return "RBRACE";
    case TOKEN_COMMA:
        return "COMMA";
    case TOKEN_INT:
        return "INT";
    case TOKEN_SEMICOLON:
        return "SEMICOLON";
    case TOKEN_EOF:
        return "EOF";
    default:
        return "! UNKNOWN TOKEN !";
    }
}

char *token_to_str(token_T *token)
{
    const char *type_str = token_type_to_str(token->type);
    const char *template = "<type=`%s`, int_type=`%d`, value=`%s`>";

    char *str = calloc(strlen(type_str) + strlen(template) + strlen(token->value), sizeof(char));
    sprintf(str, template, type_str, token->type, token->value);

    return str;
}