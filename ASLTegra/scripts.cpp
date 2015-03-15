#include <stdlib.h>

void doSystemCalls(char c)
{
    // 'y' 'o' (in sequence) will send a "YO!" to subscribers to YOASL
    static bool yoFlag = false;

    switch (c) {
    case 'o':
        if (yoFlag) {
            yoFlag = false;
            system("curl --data ""api_token=ccb12be3-cd26-49a6-abbd-e53ad3447ee8"" http://api.justyo.co/yoall/");
        }

        break;

    case 'v':
        system("firefox http://nvidia.com");
        yoFlag = false;
        break;

    case 'y':
        yoFlag = true;
        break;

    default:
        yoFlag = false;
    }
}

