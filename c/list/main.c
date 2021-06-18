#include "list.h"

int main()
{
    // 单向链表（不带头结点）测试
    LNode table;
    table.data = 0;
    table.next = NULL;

    head_insert(&table);
    //tail_insert(&table);
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

    // 单链表测试（带头结点）
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

    return 0;
}
