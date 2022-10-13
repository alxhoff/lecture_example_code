#ifndef __HELLO_OBJECT_H__
#define __HELLO_OBJECT_H__

// This typedef simply lets us use String_t to reference a void pointer
// Reminder that a void pointer is a pointer to a memory address of an
// unknown data type, ie. the compiler does not know how many bytes at
// the specified address belong to our data structure, and thus, without
// manual type casting the compiler cannot access the structure, thus
// forcing users to use the API functions we have written.
typedef void *String_t;

/**
 * @brief Returns an empty string handle
 *
 * @return String_t NULL on error
 */
String_t newEmptyString();

/**
 * @brief Returns a string handle containing the provided string
 *
 * @param str String to set
 * @return String_t NULL on error
 */
String_t newString(char *str);

/**
 * @brief Set the String object
 *
 * @param string_handle Handle to the string object which should be set
 * @param str Character array to be set inside the provided string object
 * @return int Non-zero on error
 */
int setString(String_t string_handle, char *str);

/**
 * @brief Frees the memory being used by a string
 *
 * @param string_handle String to be freed
 */
void freeString(String_t *string_handle);

/**
 * @brief Get the Length object
 *
 * @param string_handle String whos length is to be retrieved
 * @return size_t Negative on error
 */
size_t getLength(String_t string_handle);

/**
 * @brief Prints to provided string
 *
 * @param string_handle Handle to the string to be printed
 */
void printString(String_t string_handle);

/**
 * @brief Concatenates two strings, placing the result in the first string
 *
 * @param first_handle Handle to the first string which will also contain the results
 * @param second_handle Second string that will be concatenated to the first
 * @return int Non-zero on error
 */
int concatenateStrings(String_t first_handle, String_t second_handle);

/**
 * @brief Returns a copy of the provided string as a char array
 *
 * @param string_handle String to be copied from
 * @return char* Pointer to the char array copy, NULL on error
 */
char *toCharArray(String_t string_handle);

#endif
