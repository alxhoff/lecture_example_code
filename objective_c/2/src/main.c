
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hello_object.h"

int main(int argc, char *argv[])
{

    // In this example we have exactly one instance of the String structure,
    // instantiated within the C file it is not accessible outside of the C
    // file and thus one must use the API function in the header to access it.
    // Major drawback here is that we only have one variable, this is not always
    // a problem though, eg. an array that manages some collection of objects,
    // for instance states in a state machine.

    if (setString("This is my string"))
        return 1;

    printString();

    printf("-> %s <- with length %d\n", getString(), getLength());

    return 0;
}
