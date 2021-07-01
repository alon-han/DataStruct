#include <stdio.h>

#define NotFound -1
#define Array_Size 10

int binary_find(const int array[], int n, int find_number);

int main(void)
{
    int array[Array_Size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int number, find_offset;

    puts("Please enter the number you want to find:");
    scanf("%d", &number);
    if ((find_offset = binary_find(array, Array_Size, number)) == NotFound)
        puts("Can not find your number in array\n");
    else
        printf("Find your number in array, and its location is %d\n", find_offset + 1);

    return 0;
}
int binary_find(const int array[], int n, int find_number)
{
    int bottom, mid, top;

    bottom = 0;
    top = n - 1;
    while (bottom <= top)
    {
        mid = (bottom + top) / 2;
        if (array[mid] < find_number)
            bottom = mid + 1;
        else if (array[mid] > find_number)
            top = mid - 1;
        else
            return mid;
    }
//    如果bottom和top收缩至相同的位置而且还没有返回的话说明该数组中不存在find_number
    return NotFound;
}