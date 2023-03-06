@echo off
for %%f in (test\*) do gcc -Wall -Wextra -Werror %%f *.c test/src/*.c && a.exe
del a.exe