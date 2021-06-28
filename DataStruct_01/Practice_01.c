#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void select_sort(int array[], int array_size);
void input_array(int array[], int array_size);
void output_array(int array[], int array_size);
void generate_array(int array[], int array_size);

int main(void)
{
    int array_size;
    clock_t time_start, time_end;   // 计算排序算法执行时间

    srand((unsigned int) time(0));
    printf("Please enter how many number you want to entered\n");
    scanf("%d", &array_size);
    int array[array_size];
    generate_array(array, array_size);
//    输入数组
//    printf("Now enter the number sequence you want to sorted:\n");
//    input_array(array, array_size);
//    输出未排序的序列
//    output_array(array, array_size);
    time_start = clock();
    select_sort(array, array_size);
    time_end = clock();
//    printf("After the select the array is :\n");
//    输出排序完成的序列
//    output_array(array, array_size);
    printf("The %dth biggest number is %d\n", array_size / 2, array[array_size / 2]);
    printf("The select sort algorithm spend %lf seconds", (float)(time_end - time_start)/CLOCKS_PER_SEC);

    return 0;
}
void output_array(int array[], int array_size)
{
    printf("Now the array is here:\n");
    for (int i = 0; i < array_size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}
void input_array(int array[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        scanf("%d", &array[i]);
}
void select_sort(int array[], int array_size)
{
    int temp;

    for (int top = 0; top < array_size - 1; ++top)
        for (int seek = top + 1; seek < array_size; ++seek)
            if (array[top] < array[seek])
            {
                temp = array[top];
                array[top] = array[seek];
                array[seek] = temp;
            }

}
void generate_array(int array[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        array[i] = rand();
}