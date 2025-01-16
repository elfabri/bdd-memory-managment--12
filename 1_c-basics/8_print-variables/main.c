/*
 * In the space provided print:

Default max threads: A
Custom perms: B
Constant pi value: C
Sneklang title: D

 * Use format specifiers to replace A-D with the already provided variables.
 * Note: do not add precision to the floating point number.
 * */

#include <stdio.h>

int main() {
    int sneklang_default_max_threads = 8;
    char sneklang_default_perms = 'r';
    float sneklang_default_pi = 3.141592;
    char *sneklang_title = "Sneklang";
    // don't touch above this line

    printf("Default max threads: %d\n", sneklang_default_max_threads);
    printf("Custom perms: %c\n", sneklang_default_perms);
    printf("Constant pi value: %f\n", sneklang_default_pi);
    printf("Sneklang title: %s\n", sneklang_title);

    return 0;
}
