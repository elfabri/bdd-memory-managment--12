/*
 * Take a look at exercise.h. Write the implementation
 * for the function prototype found there back in exercise.c.
 * It should calculate whether the temperature is too cold
 * or too hot (in Fahrenheit of course, the most reasonable
 * scale for regular living dumbs).

Less than 70 returns "too cold".
More than 90 returns "too hot".
Otherwise returns "just right".

Note: Do not add the \n to the end of the strings. That's done at print-time.
 */

#include "exercise.h"

char *get_temperature_status(int temp) {
    if (temp > 90) {
        return "too hot";
    } else if (temp < 70) {
        return "too cold";
    } else {
        return "just right";
    }
}
