#ifndef _THREAD_TREE_H_
#define _THREAD_TREE_H_

#include <stdio.h>
#include <stdlib.h>

#define T_OK 0
#define T_FAIL -1

// 线索二叉树结点定义
typedef struct TNode
{
    int data;                    // 数据域
    int lflag;                   // 标记域，0表示指向左结点，1表示指向直接前驱
    struct TNode *left;          // 指针域，指向左结点或者直接前驱
    int rflag;                   // 标记域，0表示指向右结点，1表示指向直接后继
    struct TNode *right;         // 指针域，指向右结点或者直接后继
}TNode;

// 构建树
TNode *build();

// 构建前序线索二叉树
void pre_thread(TNode **root);

// 构建中序线索二叉树
void in_thread(TNode **root);

// 返回第一个结点
TNode *first_node(TNode *root);

// 寻找后继
TNode *next_node(TNode *root);

#endif
