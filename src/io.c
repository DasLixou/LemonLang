#include "include/io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *io_read_file(const char *filename)
{
    FILE *textfile;
    char *text;
    long numbytes;

    textfile = fopen(filename, "r");
    if (textfile == NULL)
        return (char *)-1;

    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    text = (char *)calloc(numbytes, sizeof(char));
    if (text == NULL)
        return (char *)-1;

    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);

    return text;
}

void io_write_file(const char *filename, char *outbuffer)
{
    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Could not open file `%s` for writing.", filename);
        exit(1);
    }

    fputs(outbuffer, file);

    fclose(file);
}