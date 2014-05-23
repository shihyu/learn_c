/*
輸出選擇動物的叫聲
*/

#include  <stdio.h>

enum animal  { Dog, Cat, Monkey, Invalid };

/*---狗叫---*/
void dog(void) {
    puts("汪汪!!");
}

/*---貓叫---*/
void cat(void) {
    puts("喵嗚!!");
}

/*---猴啼---*/
void monkey(void) {
    puts("吱吱!!");
}

/*---選擇動物---*/
enum animal select(void) {
    int    tmp;

    do {
        printf("0...狗    1...貓   2...猴   3...結束：");
        scanf("%d", &tmp);
    } while (tmp < Dog ||  tmp > Invalid);

    return (tmp);
}

int main(void) {
    enum animal  selected;

    do {
        switch (selected = select()) {
        case Dog     :
            dog();
            break;

        case Cat     :
            cat();
            break;

        case Monkey  :
            monkey();
            break;
        }
    } while (selected != Invalid);

    return (0);
}
