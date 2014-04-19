/* server.c */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

int port = 8000;

int main(void) {
    struct sockaddr_in    sin;
    struct sockaddr_in    pin;
    int   mysock;
    int   tempsock;
    int   addrsize;
    char  str[100], str1[20], str2[20], str3[20];
    char  buf[100];
    int   i, len1, len2;
    float c;
    mysock = socket(AF_INET, SOCK_STREAM, 0);

    if (mysock == -1) {
        perror("call to socket");
        exit(1);
    }

    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(port);

    if (bind(mysock, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("call to bind");
        exit(1);
    }

    if (listen(mysock, 20) == -1) {
        perror("call to listen");
        exit(1);
    }

    printf("Accepting connections ...\n");

    while (1) {
        tempsock = accept(mysock, (struct sockaddr *)&pin, &addrsize);

        if (tempsock == -1) {
            perror("call to accept");
            exit(1);
        }

        len1 = recv(tempsock, str, 100, 0);
        printf("\n收到字元數: %d\n", len1);
        str[len1] = 0;
        printf("received from client: %s\n", str);

        if (len1 > 0) {
            strcpy(str1, strtok(str, " "));
            printf("第 1 個字串為: %s\n", str1);
            strcpy(str2, strtok(NULL, " "));
            printf("第 2 個字串為: %s\n", str2);
            strcpy(str3, strtok(NULL, " "));
            printf("第 3 個字串為: %s\n", str3);
            c = atof(str3) * 1.05;
            sprintf(buf, "品號為 %s\n品名為 %s\n含稅價為: %.2f\n", str1, str2, c);
        }

        len2 = strlen(buf);

        if (send(tempsock, buf, len2, 0) == -1) {
            perror("call to send");
            exit(1);
        }

        close(tempsock);
    }

    return 0;
}
