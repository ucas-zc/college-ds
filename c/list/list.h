#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>

#define L_FAIL -1
#define L_OK 0

// 单向链表结点定义
typedef struct LNode
{
    int data;                // 数据域，类型可改变
    struct LNode *next;      // 后向指针
}LNode;

// 头插法建立单链表(带头结点)
int head_insert(LNode *table);

// 尾插法
int tail_insert(LNode *table);

// 中间插入数据
int insert_data(LNode *table, int data, int pos_data);

// 删除指定结点
int delete_data(LNode *table, int data);

// 遍历链表
int display_list(LNode *table);

// 销毁链表
int destroy_list(LNode *table);

// 查找结点
LNode *find_node(LNode *table, int data);

// 计算表长
int get_len(LNode *table);

// 头插法建立单链表(不带头结点)
int nhead_insert(LNode **table);

// 尾插法建立单链表(不带头结点)
int ntail_insert(LNode **table);

// 中间插入数据（不带头文件）
int ninsert_data(LNode **table, int data, int pos_data);

// 删除指定结点
int ndelete_data(LNode **table, int data);

// 查找结点
LNode *nfind_node(LNode **table, int data);

// 遍历链表
int ndisplay_list(LNode **table);

// 销毁链表
int ndestroy_list(LNode **table);

// 计算表长
int nget_len(LNode **table);

#endif
