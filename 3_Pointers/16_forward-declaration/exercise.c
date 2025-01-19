#include <stdio.h>
#include <stdlib.h>

#include "exercise.h"

snekobject_t new_node(char *name) {
  snekobject_t node = {
    .name = name,
    .child = NULL
  };
  return node;
}
