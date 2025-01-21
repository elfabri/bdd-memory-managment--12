/* Sneklang is going to need objects.
 * We'll hand-code those objects, and Sneklang developers
 * will use them to store dynamic variables,
 * kinda like Python. Everything is an object,
 * even simple integers and strings!
 *
 * Take a look at the SnekObject struct in exercise.h.
 * It has a kind field that stores the type of the object
 * (like INTEGER or STRING) and a data field
 * that stores the actual data.
 *
 * Create a snek_object_kind_t enum type in exercise.h.
 * It's the one used as the kind field of the provided SnekObject.
 * It's an enum that can be an INTEGER (0) or a STRING (1).
 *
 * Complete the format_object function in exercise.c
 * that uses a switch on the .kind of a snek_object_t
 * and writes a formatted string to the associated buffer.
 *
 * For an integer, write int:n to the buffer,
 * replacing n with the integer value
 *
 * For a string, write string:str to the buffer,
 * replacing str with the string value
 * 
 * You can use sprintf to write the formatted string to the buffer
 */

#include <stdio.h>

#include "exercise.h"

void format_object(snek_object_t obj, char *buffer) {
    switch (obj.kind) {
        case INTEGER:
            sprintf(buffer,"int:%d", obj.data.v_int);
            break;
        case STRING:
            sprintf(buffer,"string:%s", obj.data.v_string);
            break;
        default:
            buffer = "";
            break;
    }
}

// don't touch below this line'

snek_object_t new_integer(int i) {
  return (snek_object_t){
    .kind = INTEGER,
    .data = {.v_int = i}
  };
}

snek_object_t new_string(char *str) {
  // NOTE: We will learn how to copy this data later.
  return (snek_object_t){
    .kind = STRING,
    .data = {.v_string = str}
  };
}
