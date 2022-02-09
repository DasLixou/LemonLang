#ifndef LEMON_TOKEN_H
#define LEMON_TOKEN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct TOKEN_STRUCT
{
    char *value;
    enum
    {
        TOKEN_ID,
        // Keywords
        TOKEN_KW_PUBLIC,
        // Symbols
        TOKEN_EQUALS,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_LBRACE,
        TOKEN_RBRACE,
        TOKEN_COMMA,
        TOKEN_INT,
        TOKEN_SEMICOLON,
        TOKEN_EOF,
    } type;
} token_T;

token_T *init_token(char *value, int type);

const char *token_type_to_str(int type);
char *token_to_str(token_T *token);
#endif // LEMON_TOKEN_H