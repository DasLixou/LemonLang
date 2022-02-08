#include <stdio.h>

#include "include/parser.h"
#include "include/token.h"

int main()
{
    printf("[lemonc] Start compiling...\n");
    lexer_T *lexer = init_lexer("someNumber = 17;");
    parser_T *parser = init_parser(lexer);
    parser_parse(parser);
}