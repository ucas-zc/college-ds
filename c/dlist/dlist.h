#ifndef _DLIST_H_
#define _DLIST_H_

#include <stdio.h>
#include <stdlib.h>

#define DL_OK 1
#define DL_FAIL -1

// 双向链表结点定义
typedef struct DLNode
{
    int data;                // 数据域，类型可改变
    struct DLNode *prev;     // 前向指针
    struct DLNode *next;     // 后向指针
}DLNode;

// 头插法
int head_insert(DLNode *table);

// 插入数据
int insert_data(DLNode *table, int data, int pos_data);

// 查找结点
DLNode *find_node(DLNode *table, int data);

// 删除结点
int delete_node(DLNode *table, int data);

// 计算表长
int get_len(DLNode *table);

// 遍历链表
int display_list(DLNode *table);

// 销毁链表
int destroy_list(DLNode *table);

#endif
