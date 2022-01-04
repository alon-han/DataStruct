#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack * Initial_Stack(int Stack_Size)
{
    Stack * S;

    if(Stack_Size < 2){
        printf("The Stack is too small");
        exit(EXIT_FAILURE);
    }
    S = malloc(sizeof(Stack));
    if (S == NULL){
        printf("There is no memory to share");
        exit(EXIT_FAILURE);
    }
    S->array = malloc(sizeof(char) * Stack_Size);
    if (S->array == NULL)
    {
        printf("There is no memory to share");
        exit(EXIT_FAILURE);
    }
    S->capacity = Stack_Size;
    S->top = -1;

    return S;
}

int IsEmpty(Stack * S){
    if (S->top == -1)
        return 1;
    else
        return 0;
}

int IsFull(Stack * S){
    if (S->top == S->capacity - 1)
        return 1;
    else
        return 0;
}

void Push(char element, Stack * S)
{
    if (IsFull(S)){
        printf("The Stack is Full! can not push element anymore\n");
        exit(EXIT_FAILURE);
    }
    S->array[++S->top] = element;
}

void Pop(Stack * S){
    if (IsEmpty(S)){
        printf("The Stack is empty, please add something first\n");
        exit(EXIT_FAILURE);
    }
    S->top--;
}

void Top_and_Pop(Stack * S){
    if (IsEmpty(S)){
        printf("The Stack is empty, please add something first\n");
        exit(EXIT_FAILURE);
    }
    printf("%c ", S->array[S->top]);
    S->top--;
}
