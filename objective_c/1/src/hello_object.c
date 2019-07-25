#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *public_message = "Hello World";

char message[100] = {0};
int message_length = 0;

void set_message( char *str )
{
    if(strlen(str) > 99){
        printf("Set string too long\n");
        return;
    }

    strcpy(message, str);
    message_length = strlen(str);
}

char *get_message( void )
{
    char *ret = malloc(sizeof(char) * (strlen(message) + 1));

    if(!ret){
        printf("Could not allocate get string\n");
        return NULL;
    }

    strcpy(ret, message);

    return ret;
}

int get_message_len( void )
{
    return message_length;
}
