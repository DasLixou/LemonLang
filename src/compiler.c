#include "include/compiler.h"

char *compile_fasm_windows_32(AST_T *structure)
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
        const char *template = "%s:\n"
                               "%s\n"
                               ".end %s\n";
        // char *nextValue = compile_fasm_windows_32(structure->value);
        value = realloc(value, (strlen(template) + (strlen(structure->name) * 2) + 1 * sizeof(char)));
        sprintf(value, template, structure->name, "invoke MessageBox,HWND_DESKTOP,\"Hi :3\",invoke GetCommandLine,MB_OK\ninvoke ExitProcess,0", structure->name);
        break;
    }
    case AST_NOOP:
    {
        const char *template = "include 'win32ax.inc' ;\n"
                               ".code\n";
        value = realloc(value, (strlen(template)) + 1 * sizeof(char));
        strcat(value, template);
        for (int i = 0; i < ((list_T *)structure->value)->size; i++)
        {
            char *next_value = compile_fasm_windows_32(((list_T *)structure->value)->items[i]);
            value = realloc(value, (strlen(value) + strlen(next_value)) * sizeof(char));
            strcat(value, next_value);
        }
        break;
    }
    default:
        printf("[lemonc.Compiler] Can't find compilation element for %d aka. %s or %p\n", structure->type, structure->name, structure->value);
    }

    return value;
}