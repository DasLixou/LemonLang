#include "include/lexer.h"

lexer_T *init_lexer(char *src)
{
    lexer_T *lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->src_size = strlen(src);
    lexer->i = 0;
    lexer->c = src[lexer->i];

    return lexer;
}

void lexer_advance(lexer_T *lexer)
{
    if (lexer->i < lexer->src_size && lexer->c != '\0')
    {
        lexer->i += 1;
        lexer->c = lexer->src[lexer->i];
    }
}

token_T *lexer_next_token(lexer_T *lexer)
{
    while (lexer->c != '\0')
    {
        lexer_skip_whitespace(lexer);

        if (isalpha(lexer->c))
        {
            return lexer_parse_id(lexer);
        }

        if (isdigit(lexer->c))
        {
            return lexer_parse_number(lexer);
        }

        switch (lexer->c)
        {
        case '=':
            return lexer_advance_current(lexer, TOKEN_EQUALS);
        case '(':
            return lexer_advance_current(lexer, TOKEN_LPAREN);
        case ')':
            return lexer_advance_current(lexer, TOKEN_RPAREN);
        case '{':
            return lexer_advance_current(lexer, TOKEN_LBRACE);
        case '}':
            return lexer_advance_current(lexer, TOKEN_RBRACE);
        case ',':
            return lexer_advance_current(lexer, TOKEN_COMMA);
        case ';':
            return lexer_advance_current(lexer, TOKEN_SEMICOLON);
        case '\0':
            break;
        default:
        {
            printf("[Lexer]: Unexpected character `%c`\n", lexer->c);
            lexer_advance(lexer);
        }
        }
    }

    return init_token(0, TOKEN_EOF);
}

// Custom Lexer Parts //

token_T *lexer_parse_id(lexer_T *lexer)
{
    char *value = calloc(1, sizeof(char));
    while (isalpha(lexer->c))
    {
        value = realloc(value, (strlen(value) + 2) * sizeof(char));
        strcat(value, (char[]){lexer->c, 0});
        lexer_advance(lexer);
    }

    if (strcmp(value, "public") == 0)
    {
        return init_token(value, TOKEN_KW_PUBLIC);
    }
    return init_token(value, TOKEN_ID);
}

token_T *lexer_parse_number(lexer_T *lexer)
{
    char *value = calloc(1, sizeof(char));

    while (isdigit(lexer->c))
    {
        value = realloc(value, (strlen(value) + 2) * sizeof(char));
        strcat(value, (char[]){lexer->c, 0});
        lexer_advance(lexer);
    }

    return init_token(value, TOKEN_INT);
}

// Helper methods //

void lexer_skip_whitespace(lexer_T *lexer)
{
    while (lexer->c == 13 || lexer->c == 10 || lexer->c == ' ' || lexer->c == '\t')
    {
        lexer_advance(lexer);
    }
}

token_T *lexer_advance_current(lexer_T *lexer, int type)
{
    char *value = calloc(2, sizeof(char));
    value[0] = lexer->c;
    value[1] = '\0';

    token_T *token = init_token(value, type);
    lexer_advance(lexer);

    return token;
}