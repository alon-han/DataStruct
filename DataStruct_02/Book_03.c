#include <stdio.h>
#include <stdbool.h>

// 欧几里得算法 计算最大公因数
unsigned int Gcd(unsigned int M, unsigned int N);
// 计算幂运算
long int Pow(long int number, unsigned int N);
static bool IsEven(unsigned int number);

int main(void)
{
    return 0;
}
unsigned int Gcd(unsigned int M, unsigned int N)
{
    unsigned int Rem;

//    注意在这个地方MN的大小是无所谓的，就算M<N第一次循环也会将两者的值给交换
    while (N > 0)
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }

    return M;
}
long int Pow(long int number, unsigned int N)
{
    if (N == 0)
        return 0;
    if (IsEven(N))
        return Pow(number * number, N / 2);
    else
        return Pow(number * number, N / 2) * number;
}
static bool IsEven(unsigned int number)
{
    return (number % 2 == 0) ? true : false;
}