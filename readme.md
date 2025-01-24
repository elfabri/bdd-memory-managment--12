# [Boot.dev](https://boot.dev) course 12 - Memory Managment

Following along with the course and experimenting a little bit with other things.

compiling with zig:
```
zig cc *.c -o result
```

compiling with gcc:
```
gcc -o result *.c
```

compiling test with [munit](https://nemequ.github.io/munit/) (installed with meson, and on an ignored folder "subprojects")
```
gcc -o test main.c exercise.c ../../subprojects/munit/munit.c
```

# tests

It seems that boot.dev has a framework or something, apart from munit, to run the test on the web, and I couldn't find that. I installed munit, then remade the tests so I could run them, but there are some asserts that I couldn't remake, so I just skipped those asserts, the rest should be good.
