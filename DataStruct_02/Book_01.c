// 最大子序列和的四种算法分析
#include <stdio.h>

#define ARRAY_SIZE 20

int MaxSubsequenceSum_Algorithm_1(const int array[], int n);
int MaxSubsequenceSum_Algorithm_2(const int array[], int n);

int main(void)
{
    return 0;
}
int MaxSubsequenceSum_Algorithm_1(const int array[], int n)
{
    int MaxSum, LocalSum;
//    最直观的解法 遍历每一个子序列 时间复杂度为O(N^3)
//    问题在于重复计算了很多求和 效率低下
    MaxSum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) {
            LocalSum = 0;
            for (int k = i; k <= j; ++k)
                LocalSum += array[k];
            if (LocalSum > MaxSum)
                MaxSum = LocalSum;
        }

    return MaxSum;
}
int MaxSubsequenceSum_Algorithm_2(const int array[], int n)
{
    int MaxSum, LocalSum;

    MaxSum = 0;
    for (int i = 0; i < n; ++i)
    {
        LocalSum = 0;
        for (int j = i; j < n; ++j) {
//            利用之前已经计算过的和来计算 无需重复计算 把时间复杂度压缩到了O(N^2)
            LocalSum += array[j];
            if (MaxSum < LocalSum)
                MaxSum = LocalSum;
        }
    }

    return MaxSum;
}