#include "search.h"

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

    return 0;
}
