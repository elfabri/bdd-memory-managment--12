/*
 * Someone allowed a Pythonista into our beautiful C codebase!
 * Fix the bugs caused by missing types on lines 4, 5, and 6.
 * */
#include <stdio.h>

int main() {
    int max_recursive_calls = 100;
    char io_mode = 'w';
    float throttle_speed = 0.2;

    // don't touch below this line
    printf("Max recursive calls: %d\n", max_recursive_calls);
    printf("IO mode: %c\n", io_mode);
    printf("throttle speed: %f\n", throttle_speed);
    return 0;
}
