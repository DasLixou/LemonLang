#include <stdio.h>

#include "include/parser.h"
#include "include/token.h"
#include "include/io.h"
#include "include/compiler.h"

int main(int argc, char *argv[])
{
    if (argv[1] == NULL)
    {
        printf("[lemonc] Please provide a file to compile.");
        return 1;
    }
    printf("[lemonc] Start compiling...\n");
    lexer_T *lexer = init_lexer(io_read_file(argv[1]));
    parser_T *parser = init_parser(lexer);
    AST_T *structure = parser_parse(parser);
    free(lexer);
    free(parser);
    io_write_file("lemon_application.asm", compile_windows_32(structure));
    free(structure);
    printf("[lemonc] Finished compiling! :D\n");
}