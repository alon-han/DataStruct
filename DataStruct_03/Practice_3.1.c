#include <stdio.h>
#include "List.h"

int main(void)
{
    List L;

    Initial_List(&L);
//    插入几个元素
    Insert_Tail(1, &L);
    Insert_Tail(2, &L);
    Insert_Tail(3, &L);
    Insert_Tail(4, &L);
//    打印单链表所有元素
    Print_Element(&L);
//    删除所有元素并且销毁链表
    DestroyList(&L);

    return 0;
}