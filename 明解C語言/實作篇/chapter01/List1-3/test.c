void detab(FILE* src, FILE* dst, int width) {
    int ch;
    int pos = 1;

    while ((ch = fgetc(src)) != EOF) {
        int num;

        switch (ch) {
        case '\t':
            num = width - (pos - 1) % width;

            for (; num > 0; num--) {
                fputc(' ', dst);
                pos++;
            }

            break;

        case '\n':
            fputc(ch, dst);
            pos = 1;
            break;

        default:
            fputc(ch, dst);
            pos++;
            break;
        }
    }
}

