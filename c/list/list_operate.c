#include "list_operate.h"

// 删除倒数第N个结点
int delete_tail(LNode *table, int n)
{
    // 异常判断
    if (table == NULL)
    {
        return L_FAIL;
    }

    // 将指针pN向后偏移n个位置
    int index = 0;
    LNode *pN = table->next;
    while (pN != NULL)
    {
        if (index == n)
            break;

        index++;
        pN = pN->next;
    }

    if (pN == NULL)
    {
        table->next = table->next->next;
        return L_OK;
    }

    // pN偏移距离少于n个则说明链表不够长
    if (index < n)
    {
        return L_FAIL;
    }

    // pNode与pN同等速度向后遍历
    // 当pN为NULL时，即pNode为倒数第n+1个结点
    LNode *pNode = table;
    while (pN != NULL)
    {
        pN = pN->next;
        pNode = pNode->next;
    }

    // 删除倒数第n个结点
    LNode *pDel = pNode->next;
    pNode->next = pDel->next;
    pDel->next = pDel;
    if (pDel != NULL)
    {
        free(pDel);
        pDel = NULL;
    }

    return L_OK;
}

LNode *find_mid(LNode *table)
{
    // 异常判断
    if (table == NULL)
    {
        return NULL;
    }

    // 设置两个指针pMid与pNode，其中pMid最终指向中间位置的结点
    // pNode一次走两个位置，pMid一次走一个位置
    LNode *pMid = table->next;
    LNode *pNode = table->next;
    while (pNode != NULL)
    {
        if (pNode->next == NULL)
        {
            break;
        }

        pMid = pMid->next;
        pNode = pNode->next->next;
    }

    return pMid;
}

// 链表反转
int reverse_list(LNode *table)
{
    // 异常判断
    if (table == NULL)
    {
        return L_FAIL;
    }

    // 逆置操作，先取下结点，再用头插法
    LNode *pNode = table->next;
    table->next = NULL;
    while (pNode != NULL)
    {
        LNode *pTemp = pNode;
        pNode = pNode->next;

        pTemp->next = table->next;
        table->next = pTemp;
    }

    return L_OK;
}

// 链表的判环
int is_cycle(LNode *table)
{
    // 异常判断
    if (table == NULL)
    {
        return L_FAIL;
    }

    // 使用两个指针pSlow与pFast，pFast一次遍历两个结点，pSlow一次走一个结点
    // 当两指针发送相遇的时候，即为环型链表
    LNode *pSlow = table;
    LNode *pFast = table->next;
    while (pSlow != NULL && pFast != NULL && pFast->next != NULL)
    {
        // 链表发生了相遇的情况，链表即为环型链表
        if (pSlow == pFast || pSlow == pFast->next)
        {
            return L_OK;
        }

        pFast = pFast->next->next;
        pSlow = pSlow->next;
    }

    return L_FAIL;
}
