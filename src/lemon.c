#include <stdio.h>

#include "include/parser.h"
#include "include/token.h"

int main()
{
    printf("[lemonc] Start compiling...\n");
    lexer_T *lexer = init_lexer("i = 1;");
    token_T *token = lexer_next_token(lexer);
    while (token != TOKEN_EOF)
    {
        printf("%s\n", token_to_str(token));
        token = lexer_next_token(lexer);
    }
    parser_T *parser = init_parser(lexer);
}