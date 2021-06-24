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
int head_insert(LNode *head);

// 尾插法
int tail_insert(LNode *head);

// 中间插入数据
int insert_data(LNode *head, int data, int pos_data);

// 删除指定结点
int delete_data(LNode *head, int data);

// 遍历链表
int display_list(LNode *head);

// 销毁链表
int destroy_list(LNode *head);

// 查找结点
LNode *find_node(LNode *head, int data);

// 计算表长
int get_len(LNode *head);

// 头插法建立单链表(不带头结点)
int nhead_insert(LNode **head);

// 尾插法建立单链表(不带头结点)
int ntail_insert(LNode **head);

// 中间插入数据（不带头文件）
int ninsert_data(LNode **head, int data, int pos_data);

// 删除指定结点
int ndelete_data(LNode **head, int data);

// 查找结点
LNode *nfind_node(LNode **head, int data);

// 遍历链表
int ndisplay_list(LNode **head);

// 销毁链表
int ndestroy_list(LNode **head);

// 计算表长
int nget_len(LNode **head);

#endif
