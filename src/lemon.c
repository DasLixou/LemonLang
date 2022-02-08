#include <stdio.h>

#include "include/parser.h"

int main()
{
    printf("[lemonc] Start compiling...");
    lexer_T *lexer = init_lexer("");
    parser_T *parser = init_parser(lexer);
}