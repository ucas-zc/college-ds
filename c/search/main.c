#include "search.h"
#include "hash.h"

int main()
{
    SqList sql;
    sql.table[0] =  0;
    sql.table[1] =  1;
    sql.table[2] =  3;
    sql.table[3] =  4;
    sql.table[4] =  6;
    sql.table[5] =  7;
    sql.table[6] =  8;
    sql.table[7] =  10;
    sql.table[8] =  15;
    sql.table[9] =  17;
    sql.length = 10;

    // 直接查找
    printf("1、pos= %d\n", search(sql, 6));
    // 折半查找
    printf("2、pos= %d\n", binary_search(sql, 17));

    // 哈希表初始化
    if (H_FAIL == init_hash_table())
    {
        printf("init hash table failed!\n");
        return H_FAIL;
    }

    insert_data(3);
    insert_data(4);
    insert_data(17780);

    search_data(3);
    display_table();

    delete_data(3);
    display_table();

    destroy_table();
    display_table();

    return H_OK;
}
