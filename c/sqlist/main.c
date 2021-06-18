#include "sqlist.h"

int main()
{
    sq_list table;
    if (SQ_FAIL == init_table(&table))
    {
        exit(-1);
    }

    if (SQ_FAIL == insert_data(&table, 6, 2))
    {
        exit(-1);
    }

    display_table(&table);

    int data = 0;
    delete_data(&table, 2, &data);
   
    display_table(&table);

    int pos = find_data(&table, 2);
    printf("pos = %d\n", pos);

    return 0;
}
