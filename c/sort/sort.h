#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>

#define MAX_SIZE 128
#define S_OK 1
#define S_FAIL -1

// 顺序表存储结构定义
typedef struct SqList
{
    int table[MAX_SIZE];         // 表内容
    int length;                  // 表长
}SqList;

// 插入排序
int insert_sort(SqList *sql);

// 折半插入排序
int binary_sort(SqList *sql);

// 冒泡排序
int bubble_sort(SqList *sql);

// 快速排序
int quick_sort(SqList *sql, int low, int high);

// 简单选择排序
int simple_select(SqList *sql);

// 归并排序
int merge_sort(SqList *sql, int low, int high);

#endif
