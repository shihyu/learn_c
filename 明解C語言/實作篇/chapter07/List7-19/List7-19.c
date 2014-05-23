/*
    offsetof的定義例
*/

#define offsetof(s, mem)    (size_t)&(((s*)0)->mem)
