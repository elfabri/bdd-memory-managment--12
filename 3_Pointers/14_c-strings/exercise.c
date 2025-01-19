/* At Sneklang, we have a bit of "not invented here" culture.
 * As such, we've decided to implement our own
 * string concatenation function.
 *
 * Complete the concat_strings function.
 * It should append str2 to the end of str1 in place.
 * Here are the steps:
 * 
 * * Find the null terminator ('\0') of str1
 * * Iterate over str2 and copy each character to the memory locations
 *   at the end of str1.
 * * Add a null terminator at the end of the concatenated string.
 * * Don't cheat and use strcat!
 *
 * str1 is already allocated with enough memory
 * to hold the concatenated string,
 * so don't worry about that.
 */
#include "exercise.h"

void concat_strings(char *str1, const char *str2) {
    // find null of str1
    int i = 0;
    while (str1[i] != '\0') {
        i++;
    }

    //str2
    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        j++;
        i++;
    }

    // add null terminator
    str1[i] = '\0';
}
