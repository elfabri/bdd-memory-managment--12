/* Complete the missing definitions in snekobject.h
 * Here's a breakdown of all that this file should define:
 *
 * 1 - An enum called snek_object_kind_t
 *     with a single value, INTEGER.
 *
 * 2 - A union called snek_object_data_t
 *     with a single member, an integer named v_int.
 *
 * 3 - A struct declaration called snek_object_t with two members:
 *        * A member of type snek_object_kind_t named kind.
 *        * A member of type snek_object_data_t named data.
 */

typedef enum SnekObjectKind {
  INTEGER,
} snek_object_kind_t;

typedef union SnekObjectData {
  int v_int;
} snek_object_data_t;

typedef struct SnekObject {
  snek_object_kind_t kind;
  snek_object_data_t data;
} snek_object_t;
