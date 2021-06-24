#include "tree.h"

int main()
{
    TNode *root = build();

    printf("-----------pre order-----------\n");
    pre_order(root);
    printf("-----------in order-----------\n");
    in_order(root);
    printf("-----------post order-----------\n");
    post_order(root);
    printf("-----------level order-----------\n");
    level_order(root);

    return T_OK;
}
