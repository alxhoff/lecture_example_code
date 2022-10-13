
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hello_object.h"

int main(int argc, char *argv[])
{

    // If we want to make a string we cannot use malloc as we don't know the structure
    //  of the String structure defined inside hello_object.c, thus we are forced to use
    //  the "public" API exposed to us through hello_object.h.
    String_t my_string = newString("This is my new string");

    // We should check that the object creation returned a non-null address, ie. the
    // string object was created and the address was returned
    if (my_string == NULL)
        return 1; // Any non-zero return value is considered an error code

    // We must use the printString function as the standard printf function does not
    // provide formatting for our String_t objects.
    printString(my_string);

    // We can use the getLength function to safely print the string's length
    printf("Length: %d\n", getLength(my_string));

    // We could use the provided function "toCharArray" to get a char* copy of the string
    // that can be printed using the formatting %s
    printf("In a char array: %s\n", toCharArray(my_string));

    // If we wanted a second string we could use the two other available functions to first
    // create an empty object and set the string, look into the source code and see how
    // many error checks the user is now being forced upon them, bad engineers being saved
    // by good code :)

    String_t my_second_string = newEmptyString();

    if (my_second_string == NULL)
        return 2;

    // In this case setString returned a non-zero value on error, thus we should check if it's
    // non-zero
    if (setString(my_second_string, "Setting my second string"))
        return 3;

    printString(my_second_string);

    // Now let's combine the two strings, the documentation tells us the result is placed into
    // the handle of the first string and the function also returns zero on success
    if (concatenateStrings(my_string, my_second_string))
        return 4;

    printString(my_string);

    // If we free the second string and then attempt to print it we will see that the API
    // functions are protecting us and our bad programming by performing checks, again
    // having a well written and restrictive API has saved the bad engineer from being
    // extra bad
    freeString(&my_second_string);
    printString(my_second_string);

    return 0;
}
