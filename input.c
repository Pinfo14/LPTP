/**
* @file input.c
* @author Emanuel Pinto
* @date 21-12-2023
* @version 1
*
* @brief Implementation of functions for handling user input.
*
* This file contains the implementation of functions designed to handle user input,
* including getting integer values within a specified range and getting string inputs.
*/


#include "stdio.h"
#include "string.h"
#include "input.h"

/**
 * @brief Cleans the input buffer by consuming characters until a newline or the end of the file is encountered.
 */
void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * @brief Gets an integer input within a specified range from the user.
 *
 * @param minVal The minimum allowed value.
 * @param maxVal The maximum allowed value.
 * @param msg The message to ask the user for input.
 * @return The user-provided integer value within the specified range.
 */
int getInt(int minVal, int maxVal, char *msg) {
    int value;
    printf(msg);

    while (scanf("%d", &value) != -1 && (value < minVal || value > maxVal)) {
        puts(ERROR);
        cleanInputBuffer();
        printf(msg);
    }

    cleanInputBuffer();
    return value;
}

/**
 * @brief Gets a string input from the user.
 *
 * @param string The buffer to store the user-provided string.
 * @param size The size of the buffer.
 * @param msg The message to ask the user for input.
 */
void getString(char *string, unsigned int size, char *msg) {
    printf(msg);

    if (fgets(string, size, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}
