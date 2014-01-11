/* cgi_reader.c */
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int   fp;
    char  buf[20];
    int   res;
    fp = open("test.txt", O_RDONLY);

    if (fp < 0) {
        strcpy(buf, "OPEN ERROR");
    } else {
        res = read(fp, buf, 10);
        buf[res] = '\0';
        close(fp);
    }

    printf("Content-type:text/html\r\n\r\n");
    printf("<html><head><title>CGI_READER</title>\r\n");
    printf("<META HTTP-EQUIV=Refresh CONTENT=10");
    printf(" URL=http://192.168.1.150/cgi-bin/cgi-reader>\r\n");
    printf("</head><body>\r\n");
    printf("<h3>Reader Value:</h3>\r\n");
    printf("%s<p>\r\n", buf);
    printf("</body></html>\r\n");
    return 0;
}


