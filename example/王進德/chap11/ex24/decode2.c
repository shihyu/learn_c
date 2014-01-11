#include "mycgi.h"
#include <stdio.h>
nv_set nv[200];
int main() {
    int   result, count;
    count = get_input(nv);
    result = atoi(nv[0].value) * atoi(nv[1].value);
    printf("Content-type:text/html;charset=big5\r\n");
    printf("\r\n");
    printf("<html><head></head><body>\n");
    printf("<h3>The result is: %d</h3>\n\n", result);
    printf("</body></html>\n");
    return 0;
}

