#include "list.h"
#include "list_operate.h"

int main()
{
#ifdef _LIST_

    // 单向链表（不带头结点）测试
    LNode table;
    table.data = 0;
    table.next = NULL;

    //head_insert(&table);
    tail_insert(&table);
    printf("len = %d\n", get_len(&table));

    display_list(&table);

    insert_data(&table, 10, 3);
    printf("len = %d\n", get_len(&table));

    display_list(&table);

    delete_data(&table, 10);
    printf("len = %d\n", get_len(&table));

    LNode *p = find_node(&table, 2);
    printf("addr:%p\n", p);

    display_list(&table);

    destroy_list(&table);
    display_list(&table);
    printf("len = %d\n", get_len(&table));

#elif _NLIST_

    // 单链表测试（不带头结点）
    LNode *tl;
    //nhead_insert(&tl);
    ntail_insert(&tl);
    ndisplay_list(&tl);
    printf("len = %d\n", nget_len(&tl));

    ninsert_data(&tl, 10, 2);
    ndisplay_list(&tl);
    printf("len = %d\n", nget_len(&tl));

    LNode *pNode = nfind_node(&tl, 2);
    printf("addr: %p\n", pNode);

    ndelete_data(&tl, 10);
    ndisplay_list(&tl);
    printf("len = %d\n", nget_len(&tl));

    ndestroy_list(&tl);
    ndisplay_list(&tl);
    printf("len = %d\n", nget_len(&tl));

#elif _OPERATE_

    LNode table;
    table.data = 0;
    table.next = NULL;

    tail_insert(&table);
    display_list(&table);

    printf("cycle=%d\n", is_cycle(&table));
   
    reverse_list(&table);
    display_list(&table);

    delete_tail(&table, 3);
    display_list(&table);

    LNode *pMid = find_mid(&table);
    if (pMid != NULL)
        printf("mid=%d\n", pMid->data);

#endif

    return 0;
}
