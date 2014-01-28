#include <stdio.h>
#include <stdarg.h>

int prompt(const char *args, ...)
{
    int ret;
    va_list ap;
    char buf[100];

    va_start(ap, args);
    ret = vsprintf(buf, args, ap);
    printf("%s\n", buf);
    va_end(ap);

    return 0;
}

int main(int argc, char *argv[])
{
    prompt("argc=%d argv[0]=%s\n", argc, argv[0]);

    return 0;
}
