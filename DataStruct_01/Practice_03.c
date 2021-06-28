#include <stdio.h>

#define INT_MAX 20
void PrintDigit(unsigned int number);

int main(void)
{
    int number = 7654321;
    int array[INT_MAX];
    unsigned int length = 0;

    while (number > 0)
    {
        array[length++] = number % 10;
        number /= 10;
    }
    for (int i = length; i >= 0; --i)
        PrintDigit(array[i]);

    return 0;
}
void PrintDigit(unsigned int number)
{
    if (number > 9 || number < 0)
        return;
    else
        printf("%d", number);
}