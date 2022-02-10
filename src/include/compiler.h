#ifndef LEMON_COMPILER_H
#define LEMON_COMPILER_H

#include <string.h>
#include <stdio.h>

#include "AST.h"
#include "list.h"

char *compile_windows_32(AST_T *structure);

#endif // LEMON_COMPILER_H