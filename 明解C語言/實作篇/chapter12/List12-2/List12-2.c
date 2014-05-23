/*
    ¨Ï¥Î°}¦Cªº½u©Ê²M³æªº¹ê§@½d¨Ò
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

#define Null    -1          /* ªÅ½s¸¹ */

typedef enum {
    Term, Insert, Append, Delete, Print, Clear
} Menu;

typedef int     Index;      /* ½s¸¹«¬ */

/*--- ¸`ÂI ---*/
typedef struct {
    int    no;          /* ·|­û½s¸¹ */
    char   name[10];        /* ¦WºÙ */
    Index  next;            /* «ü¦V«áÄò¤¸¯Àªº½s¸¹ */
    Index  Dnext;           /* §R°£²M³æ«ü¼Ğ */
} Node;

/*--- ½u©Ê²M³æ ---*/
typedef struct {
    Node*   n;              /* ²M³æ¥»Åé(°}¦C) */
    Index  top;             /* «ü¦V²M³æ«eÀY¤¸¯Àªº½s¸¹ */
    Index  max;             /* «ü¦V¨Ï¥Î°O¿ıªº³Ì¤j½s¸¹ */
    Index  deleted;         /* «ü¦V§R°£²M³æªº«eÀY¤¸¯Àªº½s¸¹ */
} List;

#define Top     (list->top)             /* ²M³æªº«eÀY */

#define Second  (list->n[Top].next)     /* ²M³æ²Ä¤G­Ó¤¸¯À */

#define Next(x) (list->n[(x)].next)     /* ²M³æ²Äx­Ó¤¸¯À */

/*--- ¹ï²M³æªº¦U¤¸¯À³]©w­È ----*/
void SetNode(Node* x, int no, char* name, Index next) {
    x->no   = no;
    x->next = next;
    strcpy(x->name, name);
}

/*--- ¶Ç¦^­n´¡¤Jªº°O¿ıªº½s¸¹ ---*/
int GetIndex(List* list) {
    if (list->deleted == Null) {        /* µL§R°£°O¿ı®É */
        return (++(list->max));
    } else {
        Index  rec = list->deleted;
        list->deleted = list->n[rec].Dnext;
        return (rec);
    }
}

/*--- ±N«ü©wªº°O¿ıµn¿ı¨ì§R°£²M³æ ---*/
void DeleteIndex(List* list, Index idx) {
    if (list->deleted == Null) {        /* µL§R°£°O¿ı®É */
        list->deleted = idx;
        list->n[idx].Dnext = Null;
    } else {
        Index  ptr = list->deleted;
        list->deleted = idx;
        list->n[idx].Dnext = ptr;
    }
}

/*--- ¦b«eÀY´¡¤J¸`ÂI ---*/
void InsertNode(List* list, int no, char* name) {
    Index  ptr = Top;
    Top = GetIndex(list);
    SetNode(&list->n[Top], no, name, ptr);
}

/*--- ¦b¥½§À´¡¤J¸`ÂI ---*/
void AppendNode(List* list, int no, char* name) {
    if (Top == Null) {                      /* ­Y²M³æ¬°ªÅªº¸Ü */
        InsertNode(list, no, name);    /* «h´¡¤J¦Ü«eÀY */
    } else {
        Index  ptr = Top;

        while (Next(ptr) != Null) {         /* §ä¥X¥½§À¸`ÂI */
            ptr = Next(ptr);
        }

        Next(ptr) = GetIndex(list);
        SetNode(&list->n[Next(ptr)], no, name, Null);
    }
}

/*--- ±N«eÀY¸`ÂI§R°£ ---*/
void DeleteNode(List* list) {
    if (Top != Null) {
        Index  ptr = Second;
        DeleteIndex(list, Top);
        Top = ptr;
    }
}

/*--- ±N¥ş¸`ÂI§R°£ ---*/
void ClearList(List* list) {
    while (Top != Null) {               /* §R°£«eÀY¸`ÂI */
        DeleteNode(list);    /* ª½¨ì²M³æ¥şªÅ */
    }
}

/*--- Åã¥Ü©Ò¦³ªº¸`ÂI ---*/
void PrintList(List* list) {
    Index  ptr = Top;

    puts("¡i¤@Äıªí¡j");

    while (ptr != Null) {
        printf("%5d %-10.10s\n", list->n[ptr].no, list->n[ptr].name);
        ptr = Next(ptr);
    }
}

/*--- ±N½u©Ê²M³æªì©l¤Æ ---*/
void InitList(List* list, int size) {
    /* ¤@¦¸½T«O¦í¤¸¯À«¬¬°Node¥B¤¸¯À¼Æ¬°sizeªº°}¦C */
    list->n = calloc(size, sizeof(Node));
    list->top = list->max = list->deleted = Null;
}

/*--- ½u©Ê²M³æ¨Ï¥Îµ²§ô ---*/
void TermList(List* list) {
    ClearList(list);                /* §R°£¥ş³¡ªº¸`ÂI */
    free(list->n);
}

/*--- ¿é¤J¸ê®Æ ---*/
Node Read(char* message) {
    Node  temp;

    printf("½Ğ¿é¤J­n%sªº¸ê®Æ¡C\n", message);

    printf("¸¹½X : ");
    scanf("%d", &temp.no);
    printf("¦WºÙ : ");
    scanf("%s", temp.name);

    return (temp);
}

/*--- ¿ï³æ¿ï¶µ ---*/
Menu SelectMenu(void) {
    int  ch;

    do {
        printf("\n(1)¦b«eÀY´¡¤J¸`ÂI	(2)¦b¥½§À´¡¤J¸`ÂI\n");
        printf("(3)§R°£«eÀYªº¸`ÂI	(4)Åã¥Ü¥ş³¡ªº¸`ÂI\n");
        printf("(5)§R°£¥ş³¡ªº¸`ÂI	(0)µ²¡@§ô¡@³B¡@²z : ");
        scanf("%d", &ch);
    } while (ch < Term  ||  ch > Clear);

    return ((Menu)ch);
}

/*--- ¥Dµ{¦¡ ---*/
int main(void) {
    Menu  menu;
    List  list;

    InitList(&list, 100);               /* Å³Ì¤j¸`ÂI¼Æ¬°100­Ó */

    do {
        Node  x;

        switch (menu = SelectMenu()) {
        case Insert:
            x = Read("´¡¤J");
            InsertNode(&list, x.no, x.name);
            break;

        case Append:
            x = Read("´¡¤J");
            AppendNode(&list, x.no, x.name);
            break;

        case Delete:
            DeleteNode(&list);
            break;

        case Print :
            PrintList(&list);
            break;

        case Clear :
            ClearList(&list);
            break;
        }
    } while (menu != Term);

    TermList(&list);
    return (0);
}
