#include <stdio.h>

#include "include/parser.h"
#include "include/token.h"
#include "include/io.h"

int main()
{
    printf("[lemonc] Start compiling...\n");
    lexer_T *lexer = init_lexer(io_read_file("example.lemon"));
    parser_T *parser = init_parser(lexer);
    parser_parse(parser);
}