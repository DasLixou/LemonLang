#ifndef LEMON_LEXER_H
#define LEMON_LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "token.h"

typedef struct LEXER_STRUCT
{
    char *src;
    size_t src_size;
    char c;
    unsigned int i;
} lexer_T;

lexer_T *init_lexer(char *src);

void lexer_advance(lexer_T *lexer);
token_T *lexer_next_token(lexer_T *lexer);

// Custom Lexer Parts //
token_T *lexer_parse_id(lexer_T *lexer);
token_T *lexer_parse_number(lexer_T *lexer);

// Helper methods //
void lexer_skip_whitespace(lexer_T *lexer);
token_T *lexer_advance_current(lexer_T *lexer, int type);

#endif // LEMON_LEXER_H