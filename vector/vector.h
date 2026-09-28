#ifndef vector_h
#define vector_h

#include <stdio.h>
#include "Head.h"

typedef struct vector//动态数组
{
    int* array;
    int size;
    int MAX_SIZE;
}vector;

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

#endif //vector_h