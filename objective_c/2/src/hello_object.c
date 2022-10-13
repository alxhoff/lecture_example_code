#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// We need this include as we want to use the typedef String_t
#include "hello_object.h"

struct String
{
    int len;
    char *str;
} my_string;

int setString(char *str)
{
    char *new_str = strdup(str);

    if (new_str == NULL)
        return -1;

    my_string.str = new_str;
    my_string.len = strlen(new_str);
}

char *getString()
{
    return strdup(my_string.str);
}

char getLength()
{
    return my_string.len;
}

void printString()
{
    printf("[len: %d] %s\n", my_string.len, my_string.str);
}