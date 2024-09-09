### Compilation instruction

```
arthur * master] pwd
/home/arthur/work/repository/static_library_obfucation_test
rm -rf build/ && cmake -DDEBUG=OFF -B build -S . && cmake --build build && nm build/libtutu.so
```   

Current result:

```
[arthur * shared_library] objdump -T build/libtutu.so 

build/libtutu.so:     file format elf64-x86-64

DYNAMIC SYMBOL TABLE:
0000000000000000  w   D  *UND*  0000000000000000  Base        _ITM_deregisterTMCloneTable
0000000000000000  w   D  *UND*  0000000000000000  Base        __gmon_start__
0000000000000000      DF *UND*  0000000000000000 (GLIBC_2.3.4) __printf_chk
0000000000000000  w   D  *UND*  0000000000000000  Base        _ITM_registerTMCloneTable
0000000000000000  w   DF *UND*  0000000000000000 (GLIBC_2.2.5) __cxa_finalize
0000000000001120 g    DF .text  0000000000000023  Base        this_is_the_only_public_function_tutu1

```   

### Test to validate library integration

```
cd test && make
./test_library
```    