#ifndef _SQ_LIST_H_
#define _SQ_LIST_H_

#include <stdio.h>
#include <stdlib.h>

#define SQ_FAIL -1
#define SQ_OK 0
#define MAX_LEN 128

// 顺序表定义
typedef struct sq_list
{
    int data[MAX_LEN];            // 数据域，类型可根据需求变更
    int length;                   // 表长
}sq_list;

// 初始化表
int init_table(sq_list *table);

// 插入数据
int insert_data(sq_list *table, int data, int pos);

// 删除数据
int delete_data(sq_list *table, int pos, int *data);

// 遍历表
int display_table(sq_list *table);

// 查找数据
int find_data(sq_list *table, int data);

#endif
