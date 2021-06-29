#include "rbtree.h"

int main()
{
    RbTree *root = NULL;
    int key = 0;
    scanf("%d", &key);
    while (key != 9999)
    {
        RbTree *node = (RbTree*)malloc(sizeof(RbTree));
        if (node == NULL)
        {
            return T_FAIL;
        }
   
        node->key = key;
        node->color = RED;

        // 插入结点
        rbtree_insert(&root, node);

        scanf("%d", &key);
    }

    pre_order(root);

    return T_OK;
}
