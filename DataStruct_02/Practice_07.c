#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
// 生成lower~upper范围的数
static unsigned int RandInt(unsigned int lower,unsigned int upper);
static void Swap(int * number_1, int * number_2);
void Generate_NaturalNumber_Algorithm_1(int array[], int n);
void Generate_NaturalNumber_Algorithm_2(int array[], int n);
void Generate_NaturalNumber_Algorithm_3(int array[], int n);

int main(void)
{
    clock_t time_start, time_end;   // 计算排序算法执行时间

    srand((unsigned int)time(NULL));
    for (int i = 10000; i <= 640000; i *= 2) {
        int array[i];
        time_start = clock();
        Generate_NaturalNumber_Algorithm_3(array, i);
        time_end = clock();
        printf("The N is %d and the algorithm 2 spend %lf seconds\n",i , (float)(time_end - time_start)/CLOCKS_PER_SEC);
    }

    return 0;
}
unsigned int RandInt(unsigned int lower,unsigned int upper)
{
    unsigned int result;

    result = lower + rand() % (upper - lower + 1);

    return result;
}
void Generate_NaturalNumber_Algorithm_1(int array[], int n)
{
    int rand_number;

    for (int i = 0; i < n; ++i) {
        rand_number = (int)RandInt(1, n);
        for (int j = 0; j < i; ++j)
            if (array[j] == rand_number)
            {
                rand_number = (int)RandInt(0, n);
                j = 0;
            }
        array[i] = rand_number;
    }
}
void Generate_NaturalNumber_Algorithm_2(int array[], int n)
{
    int Used[n];
    int rand_number;

//    初始化附加数组
    for(int i = 0; i < n; ++i)
        Used[i] = 0;
    for (int i = 0; i < n; ++i)
    {
        rand_number = (int) RandInt(1, n);
//        如果这个随机数为已经被使用过 那么重新生成一个
        while (Used[rand_number - 1] == 1)
            rand_number = (int) RandInt(1, n);
        array[i] = rand_number;
        Used[rand_number - 1] = 1;
    }
}
static void Swap(int * number_1, int * number_2)
{
    int temp;

    temp = * number_1;
    *number_1 = *number_2;
    *number_2 = temp;
}
void Generate_NaturalNumber_Algorithm_3(int array[], int n)
{
//    按照循序初始化数组
    for (int i = 0; i < n; ++i)
        array[i] = i + 1;
//    进行交换
    for (int i = 0; i < n; ++i)
        Swap(&array[i], &array[RandInt(0, i)]);
}