#include <stdio.h>

#include "include/parser.h"
#include "include/token.h"

int main()
{
    printf("[lemonc] Start compiling...\n");
    lexer_T *lexer = init_lexer("i = 1;");
    parser_T *parser = init_parser(lexer);

    token_T *token = init_token("i", TOKEN_ID);
    printf("%s", token_to_str(token));
}