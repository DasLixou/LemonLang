#include "include/compiler.h"

char *compile_windows_32(AST_T *structure)
{
    char *value = calloc(1, sizeof(char));

    switch (structure->type)
    {
    case AST_ASSIGNMENT:
    {
        const char *template = "";
        value = realloc(value, (strlen(template) + (strlen(structure->name) + strlen(structure->value)) + 1 * sizeof(char)));
        sprintf(value, template, structure->name, structure->value);
        break;
    }
    case AST_FUNCTION_DECLARATION:
    {
        const char *template = "_%s:\n";
        value = realloc(value, (strlen(template) + (strlen(structure->name)) + 1 * sizeof(char)));
        sprintf(value, template, structure->name, structure->value);
        break;
    }
    case AST_NOOP:
    {
        const char *template = "    global	_main\n"
                               "    extern	_printf\n"
                               "    section .text\n";
        value = realloc(value, (strlen(template)) + 1 * sizeof(char));
        strcat(value, template);
        for (int i = 0; i < ((list_T *)structure->value)->size; i++)
        {
            char *next_value = compile_windows_32(((list_T *)structure->value)->items[i]);
            value = realloc(value, (strlen(value) + strlen(next_value)) * sizeof(char));
            strcat(value, next_value);
        }
        break;
    }
    default:
        printf("[lemonc.Compiler] Can't find compilation element for %d\n", structure->type);
    }

    return value;
}