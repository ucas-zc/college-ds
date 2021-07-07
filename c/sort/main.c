#include "sort.h"

void display_sqlist(SqList sql)
{
    printf("[");

    int index = 0;
    for (; index < sql.length; ++index)
    {
        printf("%d ", sql.table[index]);
    }

    printf("]\n");
}

int main()
{
    // 直接插入排序
    SqList sql;
    sql.table[0] = 99;
    sql.table[1] = 10;
    sql.table[2] = 30;
    sql.table[3] = 66;
    sql.table[4] = 34;
    sql.table[5] = 77;
    sql.length = 6;

    insert_sort(&sql);
    printf("after insert sort:");
    display_sqlist(sql);

    // 折半插入排序
    sql.table[0] = 99;
    sql.table[1] = 10;
    sql.table[2] = 30;
    sql.table[3] = 66;
    sql.table[4] = 34;
    sql.table[5] = 77;
    sql.length = 6;
    binary_sort(&sql);
    printf("after binary sort:");
    display_sqlist(sql);

    sql.table[0] = 99;
    sql.table[1] = 10;
    sql.table[2] = 30;
    sql.table[3] = 66;
    sql.table[4] = 34;
    sql.table[5] = 77;
    sql.length = 6;
    bubble_sort(&sql);
    printf("after bubble sort:");
    display_sqlist(sql);

    sql.table[0] = 34;
    sql.table[1] = 10;
    sql.table[2] = 30;
    sql.table[3] = 66;
    sql.table[4] = 99;
    sql.table[5] = 77;
    sql.length = 6;
    quick_sort(&sql, 0, 5);
    printf("after quick sort:");
    display_sqlist(sql);

    sql.table[0] = 34;
    sql.table[1] = 10;
    sql.table[2] = 30;
    sql.table[3] = 66;
    sql.table[4] = 99;
    sql.table[5] = 77;
    sql.length = 6;
    simple_select(&sql);
    printf("after simple select:");
    display_sqlist(sql);

    return S_OK;
}
