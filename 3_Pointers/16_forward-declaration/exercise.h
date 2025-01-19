/* Sneklang, like Python, is built on the idea of dynamic objects,
 * and objects need to be able to store other objects.
 *
 * Run the code in its current state. Notice that the .h file
 * is producing an error because the Object struct references itself.
 * Fix it with a forward declaration.
 */
typedef struct SnekObject snekobject_t;

typedef struct SnekObject {
  char *name;
  snekobject_t *child;
} snekobject_t;

snekobject_t new_node(char *name);
