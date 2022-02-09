#ifndef LEMON_AST_H
#define LEMON_AST_H

#include <stdlib.h>

typedef struct AST_STRUCT
{
    enum
    {
        AST_ASSIGNMENT,
    } type;
    char *name;
    char *value;
} AST_T;

AST_T *init_ast(int type);

#endif // LEMON_AST_H