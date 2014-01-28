a:a.o
	gcc a.o -o a
a.o:a.s
	gcc -c a.s -o a.o
a.s:a.i
	gcc -S a.i -o a.s
a.i:a.c
	gcc -E a.c -o a.i
.PHONY:clean
clean:
	rm -f a.o a.s a.i a
