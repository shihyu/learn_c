@echo off
gcc -c %1 -o temp1.obj
gcc -c %2 -o temp2.obj
gcc temp1.obj temp2.obj -o %3
del temp1.obj
del temp2.obj
@echo on