#include "List.h"
#include <stdio.h>
#include <stdlib.h>


void Initial_List(List * L)
{
    L->next = NULL;
    L->element = 0;
}
int IsEmpty(List * L)
{
    return L->next == NULL;
}
List * Find(int element, List * L)
{
//    如果该链表为空，那么退出程序
    if (IsEmpty(L)){
        printf("The List is empty\n");
        exit(EXIT_FAILURE);
    }
    List * find = L->next;
//    如果find指向的元素的值和element不相等，那么find就指向后一个元素
    while (find->element != element && find != NULL)
        find = find->next;

    return find;
}
List * FindPrevious(int element, List * L)
{
    if (IsEmpty(L)){
        printf("The List is empty\n");
        exit(EXIT_FAILURE);
    }
    List * find = L;
    while ((find->next)->element != element)
        find = find->next;

    return find;
}
void Delete(int element, List * L)
{
    List * position = Find(element, L);
//    如果没有找到该位置
    if (position == NULL)
    {
        printf("Can not the node, you want to delete\n");
        return;
    }
    List * pre_position = FindPrevious(element, L);

    pre_position->next = position->next;
    free(position);
}
void Insert_Tail(int element, List * L)
{
    List * new_node;
    List * last = L;
    new_node = malloc(sizeof (List));
    if (new_node == NULL)
    {
        printf("can not allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    new_node->element = element;
    new_node->next = NULL;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}
void Print_Element(List * L)
{
    List * temp = L->next;

    while (temp != NULL)
    {
        printf("%d ", temp->element);
        temp = temp->next;
    }
}
void DestroyList(List * L)
{
    List * temp = L->next;

    while (temp != NULL)
    {
        L->next = temp->next;
        free(temp);
        temp = L->next;
    }
}