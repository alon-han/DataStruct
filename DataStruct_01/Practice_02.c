#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 判断是否为字符的四元组
typedef struct {
    int row;
    int col;
    int direction;
    int letter_count;
} Letter_Vector;
// 单词表和字谜表的常量
#define LENGTH 4
#define HEIGHT 4
#define WORD_COUNT 4
// 一些方向常量的定义
#define Direction_Count 8
enum direction{
    Up, Down, Left, Right, Slope_Up_Left, Slope_Up_Right, Slope_Down_Left, Slope_Down_Right
};
char * Direction[Direction_Count] = {"Up", "Down", "Left", "Right", "Slope_Up_Left", "Slope_Up_Right", "Slope_Down_Left", "Slope_Down_Right"};
#define MAX_WORD_LENGTH 4

bool Judge_Word(const Letter_Vector * vector, char * string[], int word_size, char letter_form[][LENGTH]);
void Print_Vector(const Letter_Vector * vector, char letter_form[][LENGTH]);
void Vector_Generate_Word(const Letter_Vector * vector, char * string, char letter_form[][LENGTH]);

int main(void)
{
//    初始化字谜表和单词表
    char letter_form[HEIGHT][LENGTH] = {
            {'t', 'h', 'i', 's'},
            {'w', 'a', 't', 's'},
            {'o', 'a', 'h', 'g'},
            {'f', 'g', 'd', 't'}
    };
    char * word_list[WORD_COUNT] = {"this", "two", "fat", "that"};
    Letter_Vector find_word;
//    使用嵌套for循环来遍历所有的情况
    for (int i = 0; i < HEIGHT; ++i)
    {
        find_word.row = i;
        for (int j = 0; j < LENGTH; ++j)
        {
            find_word.col = j;
            for (int k = Up; k <= Slope_Down_Right; ++k)
            {
                find_word.direction = k;
//                使用continue语句跳过不存在的方向
                if (i == 0 && (k == Up || k == Slope_Up_Left || k == Slope_Up_Right))
                    continue;
                if (j == 0 && (k == Left || k == Slope_Up_Left || k == Slope_Down_Left))
                    continue;
                if (j == LENGTH - 1 && (k == Right || k == Slope_Up_Right || k == Slope_Down_Right))
                    continue;
                if (i == HEIGHT - 1 && (k == Down || k == Slope_Down_Right || k == Slope_Down_Left))
                    continue;
                for (int l = 0; l <= MAX_WORD_LENGTH; ++l)
                {
                    find_word.letter_count = l;
                    if (Judge_Word(&find_word, word_list, WORD_COUNT, letter_form))
                        Print_Vector(&find_word, letter_form);
                }
            }
        }
    }

    return 0;
}
bool Judge_Word(const Letter_Vector * vector, char * string[], int word_size, char letter_form[][LENGTH])
{
//    初始化一个字符数组为一个字符串
    char vector_word[MAX_WORD_LENGTH + 1] = {'\0'};
//    由向量信息生成字符串
    Vector_Generate_Word(vector, vector_word, letter_form);
    for (int i = 0; i < word_size; ++i) {
        if (strcmp(vector_word, string[i]) == 0)
            return true;
    }
//    如果遍历完整个指针数组均没有找到 那么则返回false
    return false;
}
void Print_Vector(const Letter_Vector * vector, char letter_form[][LENGTH])
{
    //    初始化一个字符数组为一个字符串
    char vector_word[MAX_WORD_LENGTH + 1] = {'\0'};
//    由向量信息生成字符串
    Vector_Generate_Word(vector, vector_word, letter_form);
    printf("The word %s start in row %d col %d， ", vector_word, vector->row + 1, vector->col + 1);
    printf("from directory %s count %d letters\n", Direction[vector->direction], vector->letter_count);
}
void Vector_Generate_Word(const Letter_Vector * vector, char * string, char letter_form[][LENGTH])
{
    int move_i, move_j;
//    第一个位置是单词的第一个字母
    move_i = vector->row;
    move_j = vector->col;
    string[0] = letter_form[move_i][move_j];
    for (int i = 1; i < vector->letter_count; ++i) {
//        匹配方向 如果方向中存在着相应的字符串 那么就移动相同的位置
        if (strstr(Direction[vector->direction], "Up") != NULL)
            move_i--;
        if (strstr(Direction[vector->direction], "Down") != NULL)
            move_i++;
        if (strstr(Direction[vector->direction], "Left") != NULL)
            move_j--;
        if (strstr(Direction[vector->direction], "Right") != NULL)
            move_j++;
//        如果下标超出限制 则直接退出
        if (move_i < 0 || move_j < 0 || move_i > HEIGHT - 1 || move_j > LENGTH - 1)
            break;
        string[i] = letter_form[move_i][move_j];
    }
}