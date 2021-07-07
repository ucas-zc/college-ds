#ifndef _RB_TREE_H_
#define _RB_TREE_H_

#include <stdio.h>
#include <stdlib.h>

#define T_OK 0
#define T_FAIL -1

// 红结点
#define RED 0
// 黑结点
#define BLACK 1

// 红黑树结构体定义
typedef struct RbTree
{
    int key;                    // 查找键值
    int color;                  // 结点颜色
    struct RbTree *left;        // 左指针
    struct RbTree *right;       // 右指针
    struct RbTree *parent;      // 父指针
}RbTree;

// 左旋
static void left_rotate(RbTree **root, RbTree *cur);

// 右旋
static void right_rotate(RbTree **root, RbTree *cur);

// 插入结点
int rbtree_insert(RbTree **root, RbTree *node);

// 修正红黑树
static int rbtree_insert_fixup(RbTree **root, RbTree *node);

// 红黑树查找
RbTree *rbtree_search(RbTree *root, int key);

// 红黑树结点删除
int rbtree_delete(RbTree **root, RbTree *node);

// 删除结点后修正
int rbtree_delete_fixup(RbTree **root, RbTree *child, RbTree *parent);

#endif
