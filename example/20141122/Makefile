CC = g++
CFLAGS = `pkg-config --cflags opencv`
LFLAGS = `pkg-config --libs opencv`

main: main.o calfeatures.o
	$(CC) $(LFLAGS) main.o calfeatures.o -o main 
main.o:main.cpp
	$(CC) -c main.cpp -o main.o 
calfeatures.o:calfeatures.cpp
	$(CC) $(CFLAGS) -c calfeatures.cpp -o calfeatures.o
	#[100%]-->Finish
clean:
	rm main *.o
