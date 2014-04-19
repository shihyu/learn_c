/* multi_client.c */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv) {
    int   z, len_inet;
    struct sockaddr_in    adr_srvr;
    int   sockfd;
    int   i;
    char  buf[256];
    memset(&adr_srvr, 0, sizeof(adr_srvr));

    if (argc == 2) {
        adr_srvr.sin_addr.s_addr = inet_addr(argv[1]);
    } else {
        adr_srvr.sin_addr.s_addr = inet_addr("192.168.1.20");
    }

    adr_srvr.sin_family = AF_INET;
    adr_srvr.sin_port = htons(9090);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket error");
        exit(1);
    }

    z = connect(sockfd, (struct sockaddr *)&adr_srvr, sizeof(adr_srvr));

    if (z == -1) {
        perror("connect error");
        exit(1);
    }

    while (1) {
        z = read(sockfd, buf, 256);

        if (z == -1) {
            perror("read error");
            exit(1);
        }

        buf[z] = 0;

        if (strncmp(buf, "stop", 4) == 0) {
            break;
        }

        printf("日期時間為: %s\n", buf);
    }

    close(sockfd);
    return 0;
}

