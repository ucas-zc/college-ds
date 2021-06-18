#include "sqlist.h"

// 初始化表
int init_table(sq_list *table)
{
    // 空指针判断
    if (table == NULL)
    {
        return SQ_FAIL;
    }

    table->data[0] = 1;
    table->data[1] = 2;
    table->data[2] = 3;
    table->data[3] = 4;
    table->data[4] = 5;
    table->length = 5;
    return SQ_OK;
}

// 插入数据
int insert_data(sq_list *table, int data, int pos)
{
    // 异常判断
    if (table == NULL || pos < 0 
                    || pos > table->length
                    || table->length + 1 > MAX_LEN)
    {
        return SQ_FAIL;
    }

    // 向后推移数据
    int index = 0;
    for (index = table->length; index >= pos; --index)
    {
        table->data[index] = table->data[index - 1];
    } 

    table->data[index + 1] = data;
    ++(table->length);
    return SQ_OK;
}

// 删除指定位置
int delete_data(sq_list *table, int pos, int *data)
{
    // 异常判断
    if (table == NULL || pos < 0 
                    || pos > table->length - 1)
    {
        return SQ_FAIL;
    }

    // 取数据，前移数据
    *data = table->data[pos];
    int index;
    for (index = pos; index < table->length; ++index)
    {
        table->data[index] = table->data[index + 1];
    }

    // 计算表长
    --(table->length);
    return SQ_OK;
}

// 遍历表
int display_table(sq_list *table)
{
    // 空指针判断
    if (table == NULL)
    {
        return SQ_FAIL;
    }

    // 遍历
    printf("sequential list:\n");
    int index = 0;
    for (; index < table->length; ++index)
    {
        printf("%d\n", table->data[index]);
    }
    printf("list length:%d\n", table->length);

    return SQ_OK;
}

// 查找数据
int find_data(sq_list *table, int data)
{
    // 空指针判断
    if (table == NULL)
    {
        return SQ_FAIL;
    }

    // 查找数据
    int index = 0;
    for (; index < table->length; ++index)
    {
        if (table->data[index] == data)
        {
            return index;
        }
    }

    return  SQ_FAIL;
}
