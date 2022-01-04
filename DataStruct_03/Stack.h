#ifndef DATASTRUCT_03_STACK_H
#define DATASTRUCT_03_STACK_H

typedef struct Stack{
    int capacity;
    int top;
    char * array;
}Stack;

// 初始化一个栈
Stack * Initial_Stack(int Stack_Size);

// 判断这个栈是否为空
int IsEmpty(Stack * S);

// 判断栈是否为满
int IsFull(Stack * S);

// 压栈函数
// 将元素element压入栈中
void Push(char element, Stack * S);

// 出栈函数
// 将栈顶元素弹出栈
void Pop(Stack * S);

// 出栈函数
// 出栈后同时将出栈元素输出
void Top_and_Pop(Stack * S);

#endif //DATASTRUCT_03_STACK_H
