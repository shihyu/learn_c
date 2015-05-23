CC = g++
CFLAGS = `pkg-config --cflags opencv`
LFLAGS = `pkg-config --libs opencv`

main: main.o scripts.o
		$(CC) main.o scripts.o -o main $(LFLAGS)
main.o:main.cpp
		$(CC) $(CFLAGS) -c main.cpp -o main.o 
scripts.o:scripts.o
		$(CC) $(CFLAGS) -c scripts.cpp -o scripts.o
			#[100%]-->Finish
clean:
		rm main *.o

