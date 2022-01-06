#include <stdio.h>
#include <string.h>
#include "Stack.h"

#define Expression_Length_MAX 50
char * s_gets(char * string, int n);

int main(void){
    char infix[Expression_Length_MAX];
    Stack * S;

    S = Initial_Stack(10);
    printf("This program will translate the infix expression into the postfix expression\n");
    printf("Please enter the infix expression:\n");
    s_gets(infix, Expression_Length_MAX);
//    遍历表达式数组
    for (int i = 0; i < strlen(infix); ++i) {
//        如果是字符则直接输出
        if (infix[i] >= 'a' && infix[i] <= 'z')
            printf("%c ", infix[i]);
//        如果是左括号则入栈
        else if (infix[i] == '(')
            Push(infix[i], S);
//        如果是有括号则出栈至左括号
        else if (infix[i] == ')'){
            while(S->array[S->top] != '(')
                Top_and_Pop(S);
            Pop(S); // 出栈左括号
        }
//        如果是*/则只出栈优先级相同的
        else if (infix[i] == '*' || infix[i] == '/') {
            while (S->array[S->top] == '*' || S->array[S->top] == '/')
                Top_and_Pop(S);
            Push(infix[i], S);
        }
//        如果是+-因为其优先级最低，所有元素都需要出栈
        else if (infix[i] == '+' || infix[i] == '-'){
            while(S->array[S->top] != '(' && S->top != -1)
                Top_and_Pop(S);
            Push(infix[i], S);
            }
    }
//    结束全部出栈
    while (!IsEmpty(S))
        Top_and_Pop(S);

    return 0;
}
char * s_gets(char * string, int n)
{
    char * result;
    char * find;

    result = fgets(string, n, stdin);
    if (result)
    {
        find = strchr(string, '\n');
        if (find)
            *find= '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return result;
}
