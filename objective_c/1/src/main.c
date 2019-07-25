#include "main.h"
#include "hello_object.h"

int main(int argc, char* argv[])
{
    char *private_message_copy = NULL;

    printf("%s\n", public_message);

    set_message("this is the private message");

    private_message_copy = get_message();

    printf("%s : length %d\n", private_message_copy, get_message_len());
    
    free(private_message_copy);

    set_message("now it is changed");

    private_message_copy = get_message();

    printf("%s : length %d\n", private_message_copy, get_message_len());
}
