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

        printf("%d:%p\n", key, node);

        // 插入结点
        rbtree_insert(&root, node);

        scanf("%d", &key);
    }

    RbTree *pNode = rbtree_search(root, 3);
    printf("search: %p\n", pNode);

    rbtree_delete(&root, pNode);

    pNode = rbtree_search(root, 3);
    printf("search: %p\n", pNode);

    return T_OK;
}
