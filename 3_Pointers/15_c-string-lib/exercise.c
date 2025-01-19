/* Complete the smart_append function.
 * It appends a src string to a dest TextBuffer struct.
 * 
 * It's called a "smart" append because the destination buffer
 * is a fixed 64 bytes, and it:
 *
 * * Checks for available space before appending.
 * * Appends as much as possible if there's not enough space.
 * * Always ensures the buffer remains null-terminated.
 * * Returns a status indicating whether the full append was possible.
 */

#include <string.h>
#include "exercise.h"

int smart_append(TextBuffer* dest, const char* src) {
    if (dest == NULL || src == NULL) {
        return 1;
    }
    int srcLen = strlen(src);
    int j = dest->length;
    const int MAX_BUFFER_SIZE = 64;

    if (j == MAX_BUFFER_SIZE) {
        // dest is full
        return 1;
    }

    int destSpace = sizeof(dest->buffer) - dest->length - 1;
    if (srcLen > destSpace) {
        // some space but not enough to full src concat
        strncat(dest->buffer, src, destSpace);
        dest->length = 63;
        dest->buffer[63] = '\0';
        return 1;
    }
    // full space for src concat
    strcat(dest->buffer, src);
    int newDestLength = dest->length + srcLen;
    dest->length = newDestLength;
    dest->buffer[newDestLength+1] = '\0';
    return 0;
}
