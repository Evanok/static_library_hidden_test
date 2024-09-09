### Compilation and test instruction

```
arthur * master] pwd
/home/arthur/work/repository/static_library_obfucation_test
rm -rf build/ && cmake -DDEBUG=OFF -B build -S . && cmake --build build && nm build/libtutu.a
```   

Current result:

````
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
```   