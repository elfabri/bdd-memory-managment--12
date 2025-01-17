/*
 * Sneklang has built-in support for graphics programming
 * (and vows to never gouge game devs...).
 *
 * Define a new struct called Coordinate in coord.h.
 * Remember, .h files are for declarations of types
 * and function prototypes. The Coordinate struct
 * should have three fields:
 *
 * x: an integer
 * y: an integer
 * z: an integer
 * */

#pragma once

struct Coordinate {
    int x;
    int y;
    int z;
};
