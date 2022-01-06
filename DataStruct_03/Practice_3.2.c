#include "List.h"
#include <stdio.h>

void PrintLots(List * L, List * P);

int main(void)
{
    List L;
    List P;

    Initial_List(&L);
    Initial_List(&P);
    Insert_Tail(1, &L);
    Insert_Tail(2, &L);
    Insert_Tail(3, &L);
    Insert_Tail(4, &L);

    Insert_Tail(1, &P);
    Insert_Tail(3, &P);
    Insert_Tail(4, &P);
//    Print_Element(&P);
    PrintLots(&L, &P);

    DestroyList(&L);
    DestroyList(&P);

    return 0;
}
void PrintLots(List * L, List * P)
{
    int L_count = 1; // 用于记录L链表到达了第几个元素了
    List * L_temp = L->next;
    List * P_temp = P->next;

    while (L_temp != NULL && P_temp != NULL)
    {
//        printf("P element is %d \n", P_temp->element);
        if (L_count == P_temp->element)
            printf("%d \n", L_temp->element);
        L_temp = L_temp->next;
        L_count++;
//        printf("L_count is %d\n", L_count);
        if (L_count > P_temp->element)
            P_temp = P_temp->next;
    }
}