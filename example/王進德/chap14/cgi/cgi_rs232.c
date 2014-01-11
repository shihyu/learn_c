#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mycgi.h"

#define BAUDRATE B9600
#define RS232 "/dev/ttyS0"

nv_set nv[200];

int main() {
    int   count;
    int   fd, res;
    struct termios oldtio, newtio;
    char  s1[1];
    printf("Content-type:text/html\r\n\r\n");
    printf("<html><head><title>LED STATE</title>\r\n");
    printf("</head><body>\r\n");
    printf("start...<p>\r\n");
    fd = open(RS232, O_RDWR | O_NOCTTY);

    if (fd < 0) {
        printf("RS232 OPEN ERROR<p>\r\n");
        printf("</body></html>\r\n");
        exit(1);
    }

    printf("RS232 Open...<p>\r\n");
    tcgetattr(fd, &oldtio);
    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    tcsetattr(fd, TCSANOW, &newtio);
    tcflush(fd, TCIOFLUSH);
    count = get_input(nv);

    if (count < 1) {
        printf("get_input error!\r\n");
        printf("</body></html>\r\n");
        exit(1);
    }

    sprintf(s1, "%s", nv[0].name);
    write(fd, s1, 1);
    printf("RS232 Close...<p>\r\n");
    close(fd);
    tcsetattr(fd, TCSANOW, &oldtio);
    printf("<h3>LED STATE:</h3>\r\n");

    if (strcmp(s1, "A") == 0) {
        printf("<p>LED Left Rotation</p>\r\n");
    }

    if (strcmp(s1, "B") == 0) {
        printf("<p>LED Rigth Rotation</p>\r\n");
    }

    if (strcmp(s1, "C") == 0) {
        printf("<p>LED All ON</p>\r\n");
    }

    if (strcmp(s1, "D") == 0) {
        printf("<p>LED All OFF</p>\r\r");
    }

    printf("<p></p>\r\n");
    printf("<p><a href='/index.htm'>BACK</a></p>\r\n");
    printf("</body></html>\r\n");
    return 0;
}

