#ifndef DATASTRUCT_03_LIST_H
#define DATASTRUCT_03_LIST_H

typedef struct List_Node{
    int element;
    struct List_Node * next;
}List;

// 初始化一个链表
void Initial_List(List * L);

// 判断链表是否为空
int IsEmpty(List * L);

// 找到值为element的结点 并返回其位置
List * Find(int element, List * L);

// 找到值为element的结点的前一个结点
List * FindPrevious(int element, List * L);

// 删除值为element的结点
void Delete(int element, List * L);

// 生成一个新结点并且插入到链表最后
void Insert_Tail(int element, List * L);

// 打印单链表所有的元素
void Print_Element(List * L);

void DestroyList(List * L);

#endif //DATASTRUCT_03_LIST_H
