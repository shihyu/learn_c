/*
¶¡±µªº§Q¥Î«ü¼Ð¾Þ§@¨­°ª
*/

#include  <stdio.h>

int main(void) {
    int    soong   = 178;            /* §º¤p·ìªº¨­°ª */
    int    chang   = 175;            /* ±i¤p¶¯ªº¨­°ª */
    int    chen    = 165;            /* ³¯¤p«óªº¨­°ª */
    int    lin     = 179;            /* ªL¤p¶¯ªº¨­°ª */

    int* may, *lily;

    may   = &soong;  /* may«ü¨ìsoong¡]³ßÅw§º¤p·ì¡^ */
    lily  = &lin;        /* lily«ü¨ìlin(³ßÅwªL¤p¶¯¡^ */

    printf("may³ßÅwªº¤Hªº¨­°ª¡G%d\n", *may);
    printf("lily³ßÅwªº¤Hªº¨­°ª¡G%d\n", *lily);

    may = &chang;       /* may«ü¨ìchang¡]§ïÅÜ¤ß·N¡^‚ð*/

    *lily = 180;        /*±N180«ü©w¨ìlily©Ò«üªºª«¥ó*/
    /*§ï¼glily³ßÅwªº¤Hªº¨­°ª */

    putchar('\n');
    printf("§º¤p·ìªº¨­°ª¡G%d\n", soong);
    printf("±i¤p¶¯ªº¨­°ª¡G%d\n", chang);
    printf("³¯¤p«óªº¨­°ª¡G%d\n", chen);
    printf("ªL¤p¶¯ªº¨­°ª¡G%d\n", lin);
    printf("may³ßÅwªº¤Hªº¨­°ª¡G%d\n", *may);
    printf("lily³ßÅwªº¤Hªº¨­°ª¡G%d\n", *lily);

    return (0);
}
