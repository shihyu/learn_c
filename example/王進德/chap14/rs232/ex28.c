#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BAUDRATE B9600
#define RS232 "/dev/ttyS0"

int main() {
    int   fd, res;
    struct termios oldtio, newtio;
    int   s1[1];
    printf("start...\n");
    fd = open(RS232, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd < 0) {
        perror("RS232 OPEN");
        exit(1);
    }

    printf("RS232 Open...\n");
    tcgetattr(fd, &oldtio);
    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    tcsetattr(fd, TCSANOW, &newtio);
    tcflush(fd, TCIOFLUSH);
    printf("RS232 Writing...\n");
    printf("<a><enter>:LED left rotation\n");
    printf("<b><enter>:LED right rotation\n");
    printf("<c><enter>:LED all on\n");
    printf("<d><enter>:LED all off\n");
    printf("<q><enter>:quit\n");

    while (1) {
        s1[0] = getchar();
        write(fd, s1, 1);

        if (s1[0] == 'q') {
            break;
        }
    }

    printf("RS232 Close...\n");
    close(fd);
    tcsetattr(fd, TCSANOW, &oldtio);
    return 0;
}

