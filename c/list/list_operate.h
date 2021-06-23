#ifndef _LIST_OPERATE_H_
#define _LIST_OPERATE_H_

#include "list.h"

// 删除链表倒数第n个结点
int delete_tail(LNode *table, int n);

// 查找链表中间位置
LNode *find_mid(LNode *table);

// 链表逆置
int reverse_list(LNode *table);

// 链表的判环
int is_cycle(LNode *table);

#endif
