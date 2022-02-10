#ifndef LEMON_AST_H
#define LEMON_AST_H

#include <stdlib.h>

typedef struct AST_STRUCT
{
    enum
    {
        AST_ASSIGNMENT,
        AST_FUNCTION_DECLARATION,
        AST_NOOP,
    } type;
    char *name;
    void *value;
} AST_T;

AST_T *init_ast(int type);

#endif // LEMON_AST_H