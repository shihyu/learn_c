#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <string.h>

int main() {
    int   fd, res, fp;
    struct termios    oldtio, newtio;
    char  buf[20];
    fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY);

    if (fd < 0) {
        printf("RS232 PORT OPEN ERROR!\n");
        exit(1);
    }

    fp = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, 755);

    if (fp < 0) {
        printf("FILE OPEN ERROR!\n");
        exit(1);
    }

    printf("OPEN: fd=%d  fp=%d\n", fd, fp);
    tcgetattr(fd, &oldtio);
    bzero(&newtio, sizeof(newtio));
    bzero(&buf, sizeof(buf));
    newtio.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 10;
    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &newtio);

    while (1) {
        printf("start reading...\n");
        res = read(fd, buf, 10);

        if (res == 10) {
            buf[res] = 0;
            printf("result= %s\n", buf);
            write(fp, buf, 10);
            break;
        } else {
            printf("READ ERROR!\n");
        }
    } /* while */

    printf("Close...\n");
    close(fd);
    close(fp);
    tcsetattr(fd, TCSANOW, &oldtio);
    return 0;
}

