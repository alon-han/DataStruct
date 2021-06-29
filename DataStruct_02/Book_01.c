// 最大子序列和的四种算法分析
#include <stdio.h>

#define ARRAY_SIZE 6

int MaxSubsequenceSum_Algorithm_1(const int array[], int n);
int MaxSubsequenceSum_Algorithm_2(const int array[], int n);
int MaxSubsequenceSum_Algorithm_3(const int array[], int n);
static int MaxSubsequenceSum_Algorithm_3_part(const int array[], int left, int right);
static int FindMAx(int number1, int number2, int number3);
int MaxSubsequenceSum_Algorithm_4(const int array[], int n);

int main(void)
{
    int array[ARRAY_SIZE] = {-2, 11, -4, 13, -5, -2};
    int (* function_point[4])(const int *, int ) =
            {MaxSubsequenceSum_Algorithm_1, MaxSubsequenceSum_Algorithm_2, MaxSubsequenceSum_Algorithm_3, MaxSubsequenceSum_Algorithm_4};

    for (int i = 0; i < 4; ++i) {
        int result;
        result = function_point[i](array, ARRAY_SIZE);
        printf("The algorithm %d result is %d\n", i + 1, result);
    }

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
int MaxSubsequenceSum_Algorithm_3(const int array[], int n)
{
    return MaxSubsequenceSum_Algorithm_3_part(array, 0, n - 1);
}
static int MaxSubsequenceSum_Algorithm_3_part(const int array[], int left, int right)
{
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBoardSum, MaxRightBoardSum;
    int LeftBoardSum, RightBoardSum;
    int center;

    if (left == right)
    {
        if (array[left] > 0)
            return array[left];
        else
            return 0;
    }
    center = (left + right) / 2;
    MaxLeftSum = MaxSubsequenceSum_Algorithm_3_part(array, left, center);
    MaxRightSum = MaxSubsequenceSum_Algorithm_3_part(array, center + 1, right);

    MaxLeftBoardSum = 0;
    LeftBoardSum = 0;
    for (int i = center; i >= left; --i) {
        LeftBoardSum += array[i];
        if (LeftBoardSum > MaxLeftBoardSum)
            MaxLeftBoardSum = LeftBoardSum;
    }
    MaxRightBoardSum = 0;
    RightBoardSum = 0;
    for (int i = center + 1; i <= right; ++i)
    {
        RightBoardSum += array[i];
        if (RightBoardSum > MaxRightBoardSum)
            MaxRightBoardSum = RightBoardSum;
    }

    return FindMAx(MaxLeftSum, MaxRightSum, MaxLeftBoardSum + MaxRightBoardSum);
}
static int FindMAx(int number1, int number2, int number3)
{
    int result;
//    比较三者中的最大值
    result = (number1 >= number2) ? number1 : number2;
    result = (result >= number3) ? result : number3;

    return result;
}
int MaxSubsequenceSum_Algorithm_4(const int array[], int n)
{
    int LocalSum, MaxSum;

    LocalSum = MaxSum = 0;

    for (int i = 0; i < n; ++i) {
        LocalSum += array[i];
        if (LocalSum > MaxSum)
            MaxSum = LocalSum;
        else if (LocalSum < 0)
            LocalSum = 0;
    }

    return MaxSum;
}