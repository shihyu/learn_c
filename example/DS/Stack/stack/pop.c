/* pop.c */
extern char stack[512];
extern int top;

char pop(void) {
    return stack[top--];
}
