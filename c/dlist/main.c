#include "dlist.h"

int main()
{
    DLNode table;
    table.next = NULL;
    head_insert(&table);
    display_list(&table);
    printf("len = %d\n", get_len(&table));

    insert_data(&table, 10, 2);
    display_list(&table);
    printf("len = %d\n", get_len(&table));

    DLNode *p = find_node(&table, 2);
    printf("addr = %p\n", p);

    delete_node(&table, 10);
    display_list(&table);
    printf("len = %d\n", get_len(&table));

    destroy_list(&table);
    printf("len = %d\n", get_len(&table));
    
    return DL_OK;
}
