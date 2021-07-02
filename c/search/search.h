#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stdio.h>

#define MAX_SIZE 128

// 顺序表存储结构定义
typedef struct SqList
{
    int table[MAX_SIZE];                       // 顺序表
    int length;                                // 表长度
}SqList;

// 直接查找
int search(SqList sql, int key);

// 折半查找
int binary_search(SqList sql, int key);

#endif
