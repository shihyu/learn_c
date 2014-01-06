/* multi_server.c */
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

int main(int argc, char *argv[]) {
  int		z, len_inet;
  struct sockaddr_in	adr_srvr, adr_clnt;
  int		sockfd, connfd;
  pid_t		PID;
  time_t	clock;
  struct tm	*tm;
  int		len_time, i;
  char		buf[256];
  
  memset(&adr_srvr, 0, sizeof(adr_srvr));
  
  if (argc ==2)
	adr_srvr.sin_addr.s_addr = inet_addr(argv[1]);
  else
	adr_srvr.sin_addr.s_addr = inet_addr("192.168.1.20");
  

  adr_srvr.sin_family = AF_INET;
  adr_srvr.sin_port = htons(9090);
 
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
	perror("socket error");
	exit(1);
  }

  z = bind(sockfd, (struct sockaddr *)&adr_srvr, sizeof(adr_srvr));
  if (z == -1) {
	perror("bind error");
	exit(1);
  }

  z = listen(sockfd, 10);
  if (z == -1) {
	perror("listen error");
	exit(1);
  }

  while(1) {
	len_inet = sizeof(adr_clnt);
	connfd = accept(sockfd, (struct sockaddr *)&adr_clnt, &len_inet);
	if (connfd == -1) {
		perror("connect error");
		exit(1);
	}
	
	PID = fork();

	if (PID > 0) {
		close(connfd);
		continue;
	}

	printf("子程序處理...\n");
	close(sockfd);
	for (i=0; i<10; i++) {
		sleep(1);
		time(&clock);
		tm = gmtime(&clock);
		len_time = strftime(buf, 256, "%A %T %D\n", tm);
	
		if (write(connfd, buf, len_time) == -1) {
			perror("write error");
			exit(1);
		}
	}
	sleep(1);
	sprintf(buf, "stop\n");
	write(connfd, buf, sizeof(buf));
	exit(0);
  }
  return 0;
}

