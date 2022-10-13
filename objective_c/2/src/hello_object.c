#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// We need this include as we want to use the typedef String_t
#include "hello_object.h"

struct String
{
    int buffer_len;
    char *str;
};

String_t newEmptyString()
{
    struct String *new_string = calloc(1, sizeof(struct String));

    if (new_string == NULL)
        return NULL;

    return (String_t)new_string;
}

String_t newString(char *str)
{
    if (str == NULL)
        goto err_invalid_str;

    struct String *ret = calloc(1, sizeof(struct String));

    if (ret == NULL)
        goto err_alloc_failed;

    ret->str = strdup(str);

    if (ret->str == NULL)
        goto err_strdup_failed;

    ret->buffer_len = strlen(ret->str) + 1;

    return (String_t)ret;

err_strdup_failed:
err_alloc_failed:
err_invalid_str:
    return NULL;
}

// This is an example of a private function, should the functionality of this
// function be required at multiple places in this file then I can write
// a function for these functionalities, but without adding them to the
// header file they cannot be used directly by a user using our API.
struct String *castString(String_t string_handle, int *err)
{
    if (string_handle == NULL)
        goto err_invalid_handle;

    struct String *cast_string = (struct String *)string_handle;

    *err = 0;

    return cast_string;

err_invalid_handle:
    *err = -1;
    return NULL;
}

/**
 * @brief Resizes a string's buffer
 *
 * @param string The struct String to be resized
 * @param size The size given should NOT include the strings termination character,
 * this is in line with strlen.
 * @return int
 */
int resizeBuffer(struct String *string, size_t size)
{
    if ((size + 1) > string->buffer_len)
    { // Need to resize our buffer
        // Note here the + 1 to the size, this is because strlen does not include the '\0'
        // termination character
        string->str = (char *)realloc(string->str, sizeof(char) * (size + 1));

        if (string->str == NULL)
        {
            string->buffer_len = 0;
            return -1;
        }

        string->buffer_len = size + 1;
    }

    return 0;
}

int setString(String_t string_handle, char *str)
{
    int err = 0;

    struct String *cast_string = castString(string_handle, &err);

    if (err)
        return err;

    size_t str_len = strlen(str);

    if (resizeBuffer(cast_string, strlen(str)))
        goto err_resize;

    strcpy(cast_string->str, str);

    return 0;
err_invalid_str:
    return -1;
err_resize:
    return -2;
}

// Note this is a double pointer as String_t is a typedef for a void *
// This is as we want to actually free the structure and ideally set the
// original pointer to NULL to avoid illegal access
void freeString(String_t *string_handle)
{
    if (string_handle == NULL)
        goto err;

    if (*string_handle == NULL)
        goto err;

    struct String *cast_string = *((struct String **)string_handle);

    if (cast_string->str)
        free(cast_string->str);

    free(cast_string);

    // This ensures that any held copies of the pointer now contain NULL and
    // this can be NULL checked, ie. if (string_pointer == NULL) -> don't use
    *(struct String **)string_handle = NULL;

err:
    return;
}

// Note here that since we store the allocated buffer length we are able to use
// the fixed-size version of strlen thus avoiding unbounded calls to strlen.
size_t getLength(String_t string_handle)
{
    if (string_handle == NULL)
        goto err_invalid_handle;

    struct String *cast_string = (struct String *)string_handle;

    if (cast_string->str == NULL)
        goto err_invalid_str;

    return strnlen(cast_string->str, cast_string->buffer_len);

err_invalid_handle:
    return (size_t)-1;
err_invalid_str:
    return (size_t)-2;
}

void printString(String_t string_handle)
{
    if (string_handle == NULL)
        goto err_invalid_handle;

    struct String *cast_string = (struct String *)string_handle;

    if (cast_string->str == NULL)
        goto err_invalid_str;

    printf("%s\n", cast_string->str);

    return;

err_invalid_handle:
err_invalid_str:
    printf("Stop being bad\n");
    return;
}

int concatenateStrings(String_t first_handle, String_t second_handle)
{
    int err;

    struct String *first_string = castString(first_handle, &err);

    if (err)
        return err;

    struct String *second_string = castString(second_handle, &err);

    if (err)
        return err;

    size_t new_str_len = getLength(first_string) + getLength(second_string);

    if (resizeBuffer(first_string, new_str_len))
        goto err_resize;

    // Here we are copying the second string into the first but offsetting the destination
    // char* by the number of character already in the first string, thus concatenating them
    // into the first string
    strcpy(first_string->str + (sizeof(char) * strlen(first_string->str)), second_string->str);

    return 0;

err_resize:
    return -2;
}

char *toCharArray(String_t string_handle)
{
    int err;

    struct String *cast_string = castString(string_handle, &err);

    if (err)
        return NULL;

    char *ret = strdup(cast_string->str);

    if (ret == NULL)
        goto err_dup;

    return ret;

err_dup:
    return NULL;
}