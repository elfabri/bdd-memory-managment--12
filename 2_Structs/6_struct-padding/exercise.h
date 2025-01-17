/* Re-arrange the fields in sneklang_var_t
 * so that the padding is optimal
 * and the tests in main.c pass.
 *
 * big, then small
 */

#pragma once

typedef struct SneklangVar {
  int value;
  int scope_level;
  char type;
  char is_constant;
  char *name;
} sneklang_var_t;
