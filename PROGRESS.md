
I am building tutu library with tutu1, tutu2, tutu3.
There are unused function, static function, static const array

### Compiling code with -g -O0 (the debug mode we are using for test, profiling etc..)

nm build/libtutu.a 

tutu1.c.o:
0000000000000000 r MY_SUPER_ARRAY
0000000000000000 T this_is_the_only_public_function_tutu1
                 U normal_tutu3_function
                 U printf

tutu2.c.o:
                 U printf
0000000000000000 t unused_static_tutu2_function
0000000000000051 T unused_tutu2_function

tutu3.c.o:
0000000000000000 t my_static_tutu3_function
0000000000000000 r MY_SUPER_ARRAY
0000000000000022 T normal_tutu3_function


-> We can see everything

### Compiling with -O3 only

tutu1.c.o:
0000000000000000 r .LC0
0000000000000000 T this_is_the_only_public_function_tutu1
                 U normal_tutu3_function
                 U __printf_chk

tutu2.c.o:
0000000000000000 r .LC0
0000000000000000 r .LC1
                 U __printf_chk
0000000000000000 T unused_tutu2_function

tutu3.c.o:
0000000000000000 T normal_tutu3_function


-> Static array dont appear anymore
-> Unused static function are hidden

### Compiling with -O3 -s only

tutu1.c.o:
0000000000000000 r .LC0
0000000000000000 T this_is_the_only_public_function_tutu1
                 U normal_tutu3_function
                 U __printf_chk

tutu2.c.o:
0000000000000000 r .LC0
0000000000000000 r .LC1
                 U __printf_chk
0000000000000000 T unused_tutu2_function

tutu3.c.o:
0000000000000000 T normal_tutu3_function

-> No change.

### Compiling with -O3 -s -fvisibility=hidden

tutu1.c.o:
0000000000000000 r .LC0
                 U normal_tutu3_function
                 U __printf_chk
0000000000000000 T this_is_the_only_public_function_tutu1

tutu2.c.o:
0000000000000000 r .LC0
0000000000000000 r .LC1
                 U __printf_chk
0000000000000000 T unused_tutu2_function

tutu3.c.o:
0000000000000000 T normal_tutu3_function

-> No change

### Adding _attribute__((visibility("hidden")))  in tutu2 unused function header declaration

tutu2.c.o:
0000000000000000 r .LC0
0000000000000000 r .LC1
                 U __printf_chk
0000000000000000 T unused_tutu2_function

-> No change !!



### adding hide_symbol.sh script method to rename object file

private_sklock0.o:
0000000000000000 r .LC0
                 U normal_tutu3_function
                 U __printf_chk
0000000000000000 T this_is_the_only_public_function_tutu1

private_sklock1.o:
0000000000000000 r .LC0
0000000000000000 r .LC1
                 U __printf_chk
0000000000000000 T unused_tutu2_function

private_sklock2.o:
0000000000000000 T normal_tutu3_function

-> Now we can at least hide source file name

### adding linker flags

Adding this:
target_compile_options(static_tutu_library PRIVATE "-Wl,--exclude-libs,ALL" "-Wl,-Bsymbolic" "-fvisibility=hidden")
target_link_options(static_tutu_library PRIVATE "-Wl,--exclude-libs,ALL" "-Wl,-Bsymbolic" "-fvisibility=hidden")

private_sklock0.o:
0000000000000000 r .LC0
                 U normal_tutu3_function
                 U __printf_chk
0000000000000000 T this_is_the_only_public_function_tutu1

private_sklock1.o:
0000000000000000 r .LC0
0000000000000000 r .LC1
                 U __printf_chk
0000000000000000 T unused_tutu2_function

private_sklock2.o:
0000000000000000 T normal_tutu3_function

-> No improvement