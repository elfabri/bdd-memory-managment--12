/* 
#ad
*/

#include <stdlib.h>
#include <string.h>

#include "snekobject.h"

snek_object_t *snek_add(snek_object_t *a, snek_object_t *b) {
  if (a == NULL || b == NULL) {
    return NULL;
  }
  
  switch (a->kind) {

  case INTEGER:
    if (b->kind == FLOAT) {
      return new_snek_float(a->data.v_int + b->data.v_float);
    } else if (b->kind == INTEGER) {
      return new_snek_integer(a->data.v_int + b->data.v_int);
    }
    return NULL;
  case FLOAT:
    if (b->kind == FLOAT) {
      return new_snek_float(a->data.v_float + b->data.v_float);
    } else if (b->kind == INTEGER) {
      return new_snek_float(a->data.v_float + b->data.v_int);
    }
    return NULL;

  case STRING:
    if (b->kind != STRING) {
      return NULL;
    }
    int lenA = strlen(a->data.v_string);
    int lenB = strlen(b->data.v_string);
    char *newStr = malloc(lenA + lenB + 1);
    strcat(newStr, a->data.v_string);
    strcat(newStr, b->data.v_string);
    snek_object_t *snekStr = new_snek_string(newStr);
    free(newStr);
    return snekStr;

  case VECTOR3:
    if (b->kind != VECTOR3) {
      return NULL;
    }
    snek_object_t *xSum = snek_add(a->data.v_vector3.x, b->data.v_vector3.x);
    snek_object_t *ySum = snek_add(a->data.v_vector3.y, b->data.v_vector3.y);
    snek_object_t *zSum = snek_add(a->data.v_vector3.z, b->data.v_vector3.z);
    snek_object_t *newVec = new_snek_vector3(xSum, ySum, zSum);
    return newVec;

  case ARRAY:
    if (b->kind != ARRAY) {
      return NULL;
    }
    int newLen = a->data.v_array.size + b->data.v_array.size;
    snek_object_t *newArr = new_snek_array(newLen);
    for (int i = 0; i < newLen; i++) {
      if (i < a->data.v_array.size) {
        snek_array_set(newArr, i, snek_array_get(a, i));
      }
      int j = i - a->data.v_array.size;
      snek_array_set(newArr, i, snek_array_get(b, j));
    }
    return newArr;
  }
  return NULL;
}

// don't touch below this line

int snek_length(snek_object_t *obj) {
  if (obj == NULL) {
    return -1;
  }

  switch (obj->kind) {
  case INTEGER:
    return 1;
  case FLOAT:
    return 1;
  case STRING:
    return strlen(obj->data.v_string);
  case VECTOR3:
    return 3;
  case ARRAY:
    return obj->data.v_array.size;
  default:
    return -1;
  }
}

snek_object_t *new_snek_array(size_t size) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  snek_object_t **elements = calloc(size, sizeof(snek_object_t *));
  if (elements == NULL) {
    free(obj);
    return NULL;
  }

  obj->kind = ARRAY;
  obj->data.v_array = (snek_array_t){.size = size, .elements = elements};
  return obj;
}

bool snek_array_set(snek_object_t *array, size_t index, snek_object_t *value) {
  if (array == NULL || value == NULL) {
    return false;
  }

  if (array->kind != ARRAY) {
    return false;
  }

  if (index >= array->data.v_array.size) {
    return false;
  }

  // Set the value directly now (already checked size constraint)
  array->data.v_array.elements[index] = value;
  return true;
}

snek_object_t *snek_array_get(snek_object_t *array, size_t index) {
  if (array == NULL) {
    return NULL;
  }

  if (array->kind != ARRAY) {
    return NULL;
  }

  if (index >= array->data.v_array.size) {
    return NULL;
  }

  // Set the value directly now (already checked size constraint)
  return array->data.v_array.elements[index];
}

snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z
) {
  if (x == NULL || y == NULL || z == NULL) {
    return NULL;
  }

  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = VECTOR3;
  obj->data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};

  return obj;
}

snek_object_t *new_snek_integer(int value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = INTEGER;
  obj->data.v_int = value;
  return obj;
}

snek_object_t *new_snek_float(float value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  obj->kind = FLOAT;
  obj->data.v_float = value;
  return obj;
}

snek_object_t *new_snek_string(char *value) {
  snek_object_t *obj = malloc(sizeof(snek_object_t));
  if (obj == NULL) {
    return NULL;
  }

  int len = strlen(value);
  char *dst = malloc(len + 1);
  if (dst == NULL) {
    free(obj);
    return NULL;
  }

  strcpy(dst, value);

  obj->kind = STRING;
  obj->data.v_string = dst;
  return obj;
}
