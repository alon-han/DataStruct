#include "List.h"
#include <stdio.h>

void Exchange_ValueByPointer(int element_1, int element_2, List * L);

int main(void)
{
    List L;

    Insert_Tail(1, &L);
    Insert_Tail(2, &L);
    Insert_Tail(3, &L);

    Print_Element(&L);


    return 0;
}
void Exchange_ValueByPointer(int element_1, int element_2, List * L)
{

}