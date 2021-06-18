#include "dlist.h"

// 头插法（带头结点）
int head_insert(DLNode *table)
{
    // 空指针判断
    if (table == NULL)
    {
        return DL_FAIL;
    }

    // 输入数据，9999结束
    int data;
    scanf("%d", &data);
    if (data == 9999)
    {
        return DL_OK;
    }

    // 定义首元结点，分配失败返回
    DLNode *pNode = (DLNode*)malloc(sizeof(DLNode));
    if (pNode == NULL)
    {
        return DL_FAIL;
    }

    // 完成首元结点插入
    pNode->data = data;
    pNode->next = NULL;
    pNode->prev = table;
    table->next = pNode;

    // 输入后续结点
    while (1) 
    {
        scanf("%d", &data);
        if (data == 9999)
        {
            break;
        }

        // 给新结点分配内存
        DLNode *pCur = (DLNode*)malloc(sizeof(DLNode));
        if (pCur == NULL)
        {
            return DL_FAIL;
        }

        // 新结点赋值并插入
        pCur->data = data;
        pCur->next = table->next;
        table->next->prev = pCur;
        pCur->prev = table;
        table->next = pCur;
    }

    return DL_OK;
}

// 插入数据
int insert_data(DLNode *table, int data, int pos_data)
{
    // 空指针判断
    if (table == NULL)
    {
        return DL_FAIL;
    }

    // 遍历链表
    DLNode *pNode = table->next;
    while (pNode != NULL)
    {
        if (pNode->data == pos_data)
        {
            DLNode *pCur = (DLNode*)malloc(sizeof(DLNode));
            if (pCur == NULL)
            {
                return DL_FAIL;
            }

            pCur->data = data;
            pCur->next = pNode->next;
            pNode->next->prev = pCur;
            pCur->prev = pNode;
            pNode->next = pCur;

            return DL_OK;
        }

        pNode = pNode->next;
    }

    return DL_FAIL;
}

// 查找结点
DLNode *find_node(DLNode *table, int data)
{
    // 空指针判断
    if (table == NULL)
    {
        return NULL;
    }

    // 遍历链表
    DLNode *pNode = table->next;
    while (pNode != NULL)
    {
        if (pNode->data == data)
        {
            return pNode;
        }

        pNode = pNode->next;
    }

    return NULL;
}

// 删除结点
int delete_node(DLNode *table, int data)
{
    // 空指针判断
    if (table == NULL)
    {
        return DL_FAIL;
    }

    // 先开始查找到对应结点
    DLNode *pNode = table->next;
    while (pNode != NULL)
    {
        if (pNode->data == data)
        {
            // 将要删除结点取下来
            DLNode *pPrev = pNode;
            pNode->prev->next = pNode->next;
            pNode->next->prev = pNode->prev;
            
            // 释放内存，删除
            if (pPrev != NULL)
            {
                free(pPrev);
                pPrev = NULL;
            }
        }

        pNode = pNode->next;
    }

    return DL_OK;
}

// 计算表长
int get_len(DLNode *table)
{
    // 空指针判断
    if (table == NULL)
    {
        return 0;
    }

    // 定义一个临时变量，计算表长
    int len = 0;

    // 遍历链表，计算表长
    DLNode *pNode = table->next;
    while (pNode != NULL)
    {
        ++len;

        pNode = pNode->next;
    }

    return len;
}

// 遍历链表
int display_list(DLNode *table)
{
    // 空指针判断
    if (table == NULL)
    {
        return DL_FAIL;
    }

    printf("---------display---------\n");

    // 遍历链表
    DLNode *pNode = table->next;
    while (pNode != NULL)
    {
        printf("%d\n", pNode->data);

        pNode = pNode->next;
    }

    return DL_OK;
}

// 销毁链表
int destroy_list(DLNode *table)
{
    if (table == NULL)
    {
        return DL_FAIL;
    }

    DLNode *pNode = table->next;
    while (pNode != NULL)
    {
        DLNode *pDelete = pNode;
        pNode = pNode->next;

        free(pDelete);
        pDelete = NULL;
    }

    table->next = NULL;
    return DL_OK;
}
