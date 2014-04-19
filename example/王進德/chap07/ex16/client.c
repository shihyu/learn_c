/* client.c */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int port = 8000;

int main(int argc, char *argv[]) {
    struct sockaddr_in    pin;
    int   mysock;
    char  buf[8192];
    char  *str = "A001 電視機 20000.00 ";

    if (argc < 2) {
        printf("使用方法: client 字串\n");
        printf("使用預設字串\n");
    } else {
        str = argv[1];
    }

    bzero(&pin, sizeof(pin));
    pin.sin_family = AF_INET;
    pin.sin_addr.s_addr = inet_addr("192.168.1.20");
    pin.sin_port = htons(port);
    mysock = socket(AF_INET, SOCK_STREAM, 0);

    if (mysock == -1) {
        perror("call to socket");
        exit(1);
    }

    if (connect(mysock, (void *)&pin, sizeof(pin)) == -1) {
        perror("call to connect");
        exit(1);
    }

    printf("Sending message %s to server ...\n", str);

    if (send(mysock, str, strlen(str), 0) == -1) {
        perror("Error in send\n");
        exit(1);
    }

    if (recv(mysock, buf, 8192, 0) == -1) {
        perror("Error in receiving\n");
        exit(1);
    }

    printf("\nResponse from server: \n\n%s\n", buf);
    close(mysock);
    return 0;
}
