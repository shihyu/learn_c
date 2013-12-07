#include <graphics.h>

int main() {
    int device = DETECT, mode;
    initgraph(&device, &mode, "c:\\tc\\bgi");
    closegraph();
    system("pause")
    return 0;
}
