#ifndef __MY_CGI_H
#define __MY_CGI_H
typedef struct name_value_set {
    char name[250];
    char value[250];
} nv_set;
extern int get_input(nv_set* nv);
#endif
