/* udp_client.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int port = 8000;

int main() {
    int   sockfd;
    int   i = 0;
    int   z;
    char  buf[80], str1[80];
    struct sockaddr_in    adr_srvr;
    FILE  *fp;
    printf("開啟檔案...\n");
    fp = fopen("product.txt", "r");

    if (fp == NULL) {
        perror("open file");
        exit(1);
    }

    printf("連結 server...\n");
    bzero(&adr_srvr, sizeof(adr_srvr));
    adr_srvr.sin_family = AF_INET;
    adr_srvr.sin_addr.s_addr = inet_addr("192.168.1.20");
    adr_srvr.sin_port = htons(port);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1) {
        perror("socket error");
        exit(1);
    }

    printf("傳送檔案內容...\n");

    for (i = 0; i < 3; i++) {
        fgets(str1, 80, fp);
        printf("第 %d 筆: %s\n", i, str1);
        sprintf(buf, "第 %d 筆: %s\n", i, str1);
        z = sendto(sockfd,
                   buf,
                   sizeof(buf),
                   0,
                   (struct sockaddr *)&adr_srvr,
                   sizeof(adr_srvr));

        if (z < 0) {
            perror("sendto error");
            exit(1);
        }
    }

    printf("傳送結束字串...\n");
    sprintf(buf, "stop\n");
    z = sendto(sockfd,
               buf,
               sizeof(buf),
               0,
               (struct sockaddr *)&adr_srvr,
               sizeof(adr_srvr));

    if (z < 0) {
        perror("sendto error");
        exit(1);
    }

    fclose(fp);
    close(sockfd);
    printf("訊息傳送結束.\n");
    exit(0);
}






