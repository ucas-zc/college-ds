#include "sort.h"

// 插入排序
int insert_sort(SqList *sql)
{
    // 异常判断
    if (sql == NULL)
    {
        return S_FAIL;
    }

    int index_i = 1;
    for (; index_i < sql->length; ++index_i)
    {
        int index_j = index_i - 1;
        int temp = sql->table[index_i];
        // 寻找插入位置
        for (; index_j >= 0 && temp < sql->table[index_j]; --index_j)
        {
            sql->table[index_j + 1] = sql->table[index_j]; 
        }

        sql->table[index_j + 1] = temp;
    }

    return S_OK;
}

// 折半插入排序
int binary_sort(SqList *sql)
{
    // 异常判断
    if (sql == NULL)
    {
        return S_FAIL;
    }

    int index_i = 1;
    for (; index_i < sql->length; ++index_i)
    {
        // 寻找合适的插入位置
        int mid;
        int temp = sql->table[index_i];
        int low = 0;
        int high = index_i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (temp < sql->table[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // 移动合适位置后面的元素，为插入腾出空间
        int index_j = index_i - 1;
        for (; index_j >= high + 1; --index_j)
        {
            sql->table[index_j + 1] = sql->table[index_j];
        }
        // 插入元素
        sql->table[index_j + 1] = temp;
    }

    return S_OK;
}

// 冒泡排序
int bubble_sort(SqList *sql)
{
    // 异常判断
    if (sql == NULL)
    {
        return S_FAIL;
    }

    // 每两两比较，将最大的元素“冒泡”到单次排序的最后
    int index_i = sql->length - 1;
    for (; index_i > 0; --index_i)
    {
        int index_j = 0;
        for (; index_j < index_i; ++index_j)
        {
            if (sql->table[index_j] > sql->table[index_j + 1])
            {
                int temp = sql->table[index_j + 1];
                sql->table[index_j + 1] = sql->table[index_j];
                sql->table[index_j] = temp;
            }
        }
    }

    return S_OK;
}

// 单次快排
static int partition(SqList *sql, int low, int high)
{
    // 异常判断
    if (sql == NULL || low < 0 || high < 0)
    {
        return -1;
    }

    // 设置”哨兵“
    int pivot = sql->table[low];

    while (low < high)
    {
        // 从高位往低位查找到比哨兵小的元素
        while (low < high && sql->table[high] >= pivot)
        {
            --high;
        }

        // 交换
        sql->table[low] = sql->table[high];

        // 从低位往高位找到比哨兵大的元素
        while (low < high && sql->table[low] <= pivot)
        {
            ++low;
        }

        // 交换
        sql->table[high] = sql->table[low];
    }

    // “哨兵”归位
    sql->table[low] = pivot;

    return low;
}

// 快速排序
int quick_sort(SqList *sql, int low, int high)
{
    // 异常判断
    if (sql == NULL || low < 0 || high < 0)
    {
        return S_FAIL;
    }

    if (low < high)
    {
        // 一次快排
        int pos = partition(sql, low, high);

        // 递归快排左边
        quick_sort(sql, low, pos - 1);
        // 递归快排右边
        quick_sort(sql, pos + 1, high);
    }

    return S_OK;
}

// 简单选择排序
int simple_select(SqList *sql)
{
    // 异常判断
    if (sql == NULL)
    {
        return S_FAIL;
    }

    int index_i = 0;
    for (; index_i < sql->length; ++index_i)
    {
        // 选择最小的元素
        int min = index_i;
        int index_j = index_i + 1;
        for (; index_j < sql->length; ++index_j)
        {
            if (sql->table[index_j] < sql->table[min])
            {
                min = index_j;
            }
        }

        // 将当前最小元素交换到相应位置
        if (index_i != min)
        {
            int temp = sql->table[index_i];
            sql->table[index_i] = sql->table[min];
            sql->table[min] = temp;
        }
    }

    return S_OK;
}
