#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>

#define T_OK 0
#define T_FAIL -1
#define Q_OK 0
#define Q_FAIL -1
#define MAX_SIZE 128

// 树结点定义
typedef struct TNode
{
    int data;               // 数据域，类型可改变
    struct TNode *left;     // 指针域，左指针
    struct TNode *right;    // 指针域，右指针
}TNode;

// 队列顺序存储结构体定义
typedef struct Cycle_Queue
{
    TNode *queue[MAX_SIZE];                 // 队列，类型可根据需求改变
    int front;                              // 对头下标
    int rear;                               // 队尾下标
}CyQueue;

// 树建立
TNode *build();

// 访问结点
static void visit(TNode *node);

// 先序遍历
int pre_order(TNode *root);

// 中序遍历
int in_order(TNode *root);

// 后续遍历
int post_order(TNode *root);

// 队列初始化
int init_queue(CyQueue *queue);

// 队列判空
int is_empty(CyQueue *queue);

// 队列判满
int is_full(CyQueue *queue);

// 入队
int push_queue(CyQueue *queue, TNode *data);

// 出队
int pop_queue(CyQueue *queue, TNode **data);

// 层次遍历
int level_order(TNode *root);

#endif
