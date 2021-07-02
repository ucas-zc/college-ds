#include "search.h"

// 顺序查找
int search(SqList sql, int key)
{
    int index;
    for (index = 0; index < sql.length; ++index)
    {
        // 关键字匹配，返回元素下标
        if (key == sql.table[index])
        {
            return index;
        }
    }

    return -1;
}

// 折半查找
int binary_search(SqList sql, int key)
{
    int low, high;
    low = 0;
    high = sql.length - 1;

    while (low <= high)
    {
        // 取中间位置
        int mid = (low + high) / 2;

        // 关键值匹配中间位置元素，查找成功
        if (key == sql.table[mid])
        {
            return mid;
        }
        // 在前半部分进行查找
        else if (key < sql.table[mid])
        {
            high = mid - 1;
        }
        // 在后半部分进行查找
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}
