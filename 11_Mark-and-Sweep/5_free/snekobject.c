#include "snekobject.h"

void snek_object_free(snek_object_t *obj) {
  if (obj == NULL) {
    return;
  }
  switch (obj->kind) {
    case INTEGER:
    case FLOAT:
      break;
    case STRING:
      free(obj->data.v_string);
      break;
    case VECTOR3: {
      // the mark-and-sweep will handle the contained objects
      break;
    }
    case ARRAY: {
      // free the elements array, but not the objects themselves
      // because the mark-and-sweep will handle that
    snek_array_t *array = &obj->data.v_array;
    free(array->elements);

    break;
    }
  }
  free(obj);
}

