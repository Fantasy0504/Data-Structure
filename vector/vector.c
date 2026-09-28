#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_SIZE 100
#define ADD_SIZE 20
#define LIMIT 1000005 //1e6 + 5
#define INF -1

void init(vector* vec);//初始化一个vector
void push_back(vector* vec,int element);//在尾部添加一个元素
void pop_back(vector* vec);//删除尾部的一个元素
void clear(vector* vec);//清空vector
void erase(vector* vec,int index);//删除下标为index的元素
int size(vector* vec);//返回vector的大小
int empty(vector* vec);//判断vector是否为空
int nth_element(vector* vec,int pos);//返回第pos位元素
void reverse(vector* vec);//翻转vector(逆序存vector)
void swap(vector* vec,int left,int right);//交换vector中的两个元素
void Bubblesort(vector* vec,int greater);////对vector排序,greater == 0为升序,greater == 1为降序
void print(vector* vec);//打印vector中的所有元素(按一个空格间隔)

void init(vector* vec)//初始化一个vector
{
    int* array = (int*)calloc(INITIAL_SIZE,sizeof(int));//分配一块初始化为0的空间
    if (array == NULL)//排除系统可用内存不足、进程的虚拟地址空间不足、申请大小过大
    {
        printf("ERROR IN CALLOC VECTOR\n");
        exit(ERROR);
    }
    //给vector初始化
    vec->array = array;
    vec->size = 0;
    vec->MAX_SIZE = INITIAL_SIZE;
}

void push_back(vector* vec,int element)//在尾部添加一个元素
{
    if (vec->size == vec->MAX_SIZE)//size和最大空间大小一致,vector需要扩容
    {
        if (vec->MAX_SIZE + ADD_SIZE > LIMIT)//预计算扩容后的大小,如果大于限制,退出程序
        {
            printf("VECTOR EXCEED LIMIT\n");
            exit(ERROR);
        }
        int* array = (int*)realloc(vec->array,(vec->MAX_SIZE + ADD_SIZE) * sizeof(int));//扩容后大小改变
        if (array == NULL)////排除系统可用内存不足、进程的虚拟地址空间不足、申请大小过大
        {
            printf("ERROR IN REALLOC VECTOR\n");
            exit(ERROR);
        }
        //更新vector的信息
        vec->array = array;
        vec->MAX_SIZE += ADD_SIZE;
    }
    vec->array[vec->size] = element;//push_back element
    vec->size++;//由于添加一个元素,vector大小加一
}

void pop_back(vector* vec)//删除尾部的一个元素
{
    if (vec->size == 0) { return; }//vector为空,不能删除尾部的元素
    vec->size--;//由于删除尾部的一个元素,vector的大小减一
}

void clear(vector* vec)//清空vector
{
    if (vec->array == NULL)//有问题或者已经清空的vector直接返回
    {
        return;
    }
    if(vec->array != NULL) { free(vec->array); vec->array = NULL;}//free掉分配的内容
    vec->size = 0;
    vec->MAX_SIZE = 0;
}

void erase(vector* vec,int index)//删除下标为index的元素
{
    if (index < 0 || index >= vec->size) { return; }//index不合法,直接返回
    for (int i = index;i < vec->size - 1;i++)//从index开始整体左移一位
    {
        vec->array[i] = vec->array[i + 1];
    }
    vec->size--;
}

int size(vector* vec)
{
    return vec->size;//返回vector的大小
}

int empty(vector* vec)
{
    return vec->size == 0 ? TRUE : FALSE;//返回vector是否为空
}

int nth_element(vector* vec,int pos)//返回第pos位元素
{
    if (pos < 0 || pos >= vec->size)//排除不合法的下标,返回INF
    {
        return INF;
    }
    return vec->array[pos];
}

void swap(vector* vec,int left,int right)//交换vector中的两个元素
{
    if (vec->size == 0) { return;}
    if (left < 0 || left >= vec->size || right < 0 || right >= vec->size) { return;}//排除不合法的left,right下标
    int temp = vec->array[left];
    vec->array[left] = vec->array[right];
    vec->array[right] = temp;  
}

void reverse(vector* vec)//翻转vector(双指针跑一遍)
{
    if (vec->size == 0) { return; }
    int left = 0;
    int right = vec->size - 1;
    while (left < right)
    {
        swap(vec,left,right);
        left++;
        right--;
    }
}

void Bubblesort(vector* vec,int greater)//对vector排序,greater == 0为升序,greater == 1为降序
{
    if (vec->size == 0) { return;}
    for (int i = 0;i < vec->size - 1;i++)
    {
        for (int j = 0;j < vec->size - 1 - i;j++)
        {
            if (greater == FALSE && vec->array[j] > vec->array[j + 1]) { swap(vec,j,j + 1);} //升序排序
            if (greater == TRUE && vec->array[j] < vec->array[j + 1]) { swap(vec,j,j + 1);} //降序排序
        }
    }
}

void print(vector* vec)
{
    for (int i = 0;i < vec->size;i++)
    {
        printf("%d ",vec->array[i]);
    }
}

