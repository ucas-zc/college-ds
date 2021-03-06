#include "thread_tree.h"

// 中序线索二叉树前向结点
TNode *in_prev = NULL;
// 前序线索二叉树前向结点
TNode *pre_prev = NULL;

// 构建树
TNode *build()
{
    int data = 0;
    scanf("%d", &data);
    if (data == 9999)
    {
        return NULL;
    }

    TNode *pNode = (TNode*)malloc(sizeof(TNode));
    if (pNode == NULL)
    {
        return NULL;
    }

    pNode->data = data;
    pNode->lflag = 0;
    pNode->rflag = 0;
    pNode->left = build();
    pNode->right = build();
    return pNode;
}

// 前序构建线索二叉树
void pre_thread(TNode **root)
{
    if (root != NULL && *root != NULL)
    {
    }
}

// 构建中序遍历二叉树
void in_thread(TNode **root)
{
    // 异常判断
    if (root != NULL && *root != NULL)
    {
        // 左子树线索化
        in_thread(&((*root)->left));

        // 左子树为空，使其指向直接前驱
        if ((*root)->left == NULL)
        {
            (*root)->left = in_prev;
            (*root)->lflag = 1;
        }

        // 直接前驱不为空，且其右结点为空
        // 使其右指针指向当前结点为其直接后继
        if (in_prev != NULL && in_prev->right == NULL)
        {
            in_prev->right = *root;
            in_prev->rflag = 1;
        }

        in_prev = *root;
        // 右子树线索化
        in_thread(&((*root)->right));
    }
}

// 返回第一个结点
TNode *first_node(TNode *root)
{
    // 空指针判断
    if (root == NULL)
    {
        return NULL;
    }

    TNode *p = root;
    while (p->lflag == 0)
    {
        p = p->left;
    }

    return p;
}

// 寻找后继
TNode *next_node(TNode *root)
{
    // 空指针判断
    if (root == NULL)
    {
        return NULL;
    }

    if (root->rflag == 0)
    {
        return first_node(root->right);
    }

    return root->right;
}
