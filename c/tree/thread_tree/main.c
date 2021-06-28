#include "thread_tree.h"

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
    in_thread(&root);

    // 线索二叉树遍历
    TNode *p;
    for (p = first_node(root); p != NULL; p = next_node(p))
    {
        printf("data: %d\n", p->data);
    }

    return T_OK;
}
