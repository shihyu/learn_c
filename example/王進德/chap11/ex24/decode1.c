#include "mycgi.h"
#include <stdio.h>
nv_set nv[200];
int main() {
    int   i, count;
    count = get_input(nv);
    printf("Content-type:text/html;Charset=big5\r\n");
    printf("\r\n");
    printf("<html><head></head><body>\n");
    printf("<h3>List:</h3>\n\n");

    for (i = 0; i < count; i++) {
        printf("<p>name=%s ", nv[i].name);
        printf("value=%s\n", nv[i].value);
    }

    printf("</body></html>\n");
    return 0;
}


