#include "thread_tree.h"

extern TNode *in_prev;

int main()
{
    // 构建树
    TNode *root = build();
    if (root == NULL)
    {
        printf("build failed!\n");
        return T_FAIL;
    }

    // 构建中序线索二叉树
    in_prev = NULL;
    in_thread(&root);
    if (in_prev != NULL)
    {
        in_prev->right = NULL;
        in_prev->rflag = 1;
    }

    // 线索二叉树遍历
    TNode *p;
    for (p = first_node(root); p != NULL; p = next_node(p))
    {
        printf("data: %d\n", p->data);
    }

    return T_OK;
}
