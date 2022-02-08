#ifndef LEMON_LEXER_H
#define LEMON_LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LEXER_STRUCT
{
    char *src;
    size_t src_size;
    char c;
    unsigned int i;
} lexer_T;

lexer_T *init_lexer(char *src);

#endif // LEMON_LEXER_H