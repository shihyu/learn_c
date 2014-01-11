/* udp_server.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int port = 8000;

int main() {
    int sockfd;
    int len;
    int z;
    char buf[256];
    struct sockaddr_in adr_inet;
    struct sockaddr_in adr_clnt;
    printf("等待 Client 端傳送資料...\n");
    bzero(&adr_inet, sizeof(adr_inet));
    adr_inet.sin_family = AF_INET;
    adr_inet.sin_addr.s_addr = inet_addr("192.168.1.20");
    adr_inet.sin_port = htons(port);
    len = sizeof(adr_clnt);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1) {
        perror("socket error");
        exit(1);
    }

    z = bind(sockfd,
             (struct sockaddr*)&adr_inet,
             sizeof(adr_inet));

    if (z == -1) {
        perror("bind error");
        exit(1);
    }

    while (1) {
        z = recvfrom(sockfd,
                     buf,
                     sizeof(buf),
                     0,
                     (struct sockaddr*)&adr_clnt,
                     &len);

        if (z < 0) {
            perror("recvfrom error");
            exit(1);
        }

        buf[z] = 0;
        printf("接收資料: %s", buf);

        if (strncmp(buf, "stop", 4) == 0) {
            printf("結束連結...\n");
            break;
        }
    }

    close(sockfd);
    exit(0);
}





