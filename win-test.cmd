@echo off
for %%f in (test\*) do gcc -Wall -Wextra -Werror %%f *.c && a.exe
rm a.exe