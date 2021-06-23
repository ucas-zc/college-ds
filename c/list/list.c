#include "list.h"

// 头插法建立单链表(带头结点)
int head_insert(LNode *table)
{
    int data;
    scanf("%d", &data);
    while (data != 9999)
    {
        LNode *pNode = (LNode*)malloc(sizeof(LNode));
        if (NULL == pNode) {
            return L_FAIL;
        }

        pNode->data = data;
        pNode->next = table->next;
        table->next = pNode;

        scanf("%d", &data);
    }

    return L_OK;
}

int tail_insert(LNode *table)
{
    int data;
    scanf("%d", &data);
    LNode *pTail = table;
    while (data != 9999)
    {
        LNode *pNode = (LNode*)malloc(sizeof(LNode));
        if (NULL == pNode) {
            return L_FAIL;
        }

        pNode->data = data;
        pTail->next = pNode;
        pTail = pNode;

        scanf("%d", &data);
    }

    return L_OK;
}

int insert_data(LNode *table, int data, int pos_data)
{
    LNode *pNode = NULL;
    pNode = table->next;
    while (pNode != NULL)
    {
        if (pNode->data == pos_data)
        {
            LNode *pCur = (LNode*)malloc(sizeof(pNode));
            if (pCur == NULL) {
                return L_FAIL;
            }

            pCur->data = data;
            pCur->next = pNode->next;
            pNode->next = pCur;

            return L_OK;
        }

        pNode = pNode->next;
    }

    return L_FAIL;    
}

// 删除某个结点
int delete_data(LNode *table, int data)
{
    LNode *pPrev = table;
    LNode *pNode = table->next;
    while (pNode != NULL)
    {
        if (pNode->data == data)
        {
            LNode *p = pNode;
            pPrev->next = pNode->next;

            if (p != NULL)
            {
                free(p);
                p = NULL;
            }

            return L_OK;
        }

        pPrev = pNode;
        pNode = pNode->next;
    }

    return L_FAIL;
}

// 查找结点
LNode *find_node(LNode *table, int data)
{
    LNode *pNode = table->next;
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

// 遍历链表
int display_list(LNode *table)
{
    printf("----------display----------\n");
    LNode *pNode = NULL;
    pNode = table->next;
    while (pNode != NULL)
    {
        printf("%d\n", pNode->data);
        pNode = pNode->next;
    }

    return L_OK;
}

// 销毁链表
int destroy_list(LNode *table)
{
    LNode *pNode = table->next;
    while (pNode != NULL)
    {
        LNode *pCur = pNode;
        pNode = pNode->next;

        if (pCur != NULL) 
        {
            free(pCur);
            pCur = NULL;
        }
    }

    table->next = NULL;
    return L_OK;
}

// 计算表长
int get_len(LNode *table)
{
    int len = 0;
    LNode *pNode = table->next;
    while (pNode != NULL)
    {
        ++len;

        pNode = pNode->next;
    }

    return len;
}

// 头插法建立单链表(带头结点)
int nhead_insert(LNode **table)
{
    int data;
    scanf("%d", &data);
    if (data == 9999)
    {
        return L_OK;
    }

    *table = (LNode *)malloc(sizeof(LNode));
    (*table)->data = data;
    (*table)->next = NULL;

    while (1) 
    {
        scanf("%d", &data);
        if (data == 9999) 
        {
            break;
        }
 
        LNode *pNode = (LNode*)malloc(sizeof(LNode));
        if (NULL == pNode) {
            return L_FAIL;
        }

        pNode->data = data;
        pNode->next = *table;
        *table = pNode;
    }

    return L_OK;
}

// 头插法建立单链表(带头结点)
int ntail_insert(LNode **table)
{
    int data;
    scanf("%d", &data);
    if (data == 9999)
    {
        return L_OK;
    }

    *table = (LNode *)malloc(sizeof(LNode));
    (*table)->data = data;
    (*table)->next = NULL;

    LNode *pTail = *table;

    while (1) 
    {
        scanf("%d", &data);
        if (data == 9999) 
        {
            break;
        }
 
        LNode *pNode = (LNode*)malloc(sizeof(LNode));
        if (NULL == pNode) {
            return L_FAIL;
        }

        pNode->data = data;
        pTail->next = pNode;
        pTail = pNode;
    }

    return L_OK;
}

// 不带头结点插入数据
int ninsert_data(LNode **table, int data, int pos_data)
{
    LNode *pNode = NULL;
    pNode = *table;
    while (pNode != NULL)
    {
        if (pNode->data == pos_data)
        {
            LNode *pCur = (LNode*)malloc(sizeof(pNode));
            if (pCur == NULL) {
                return L_FAIL;
            }

            pCur->data = data;
            pCur->next = pNode->next;
            pNode->next = pCur;

            return L_OK;
        }

        pNode = pNode->next;
    }

    return L_FAIL;    
}

// 删除某个结点
int ndelete_data(LNode **table, int data)
{
    LNode *pPrev = NULL;
    LNode *pNode = *table;
    while (pNode != NULL)
    {
        if (pNode->data == data)
        {
            LNode *p = pNode;
            if (pPrev == NULL)
            {
                *table = pNode->next;
            }
            else
            {
                pPrev->next = pNode->next;
            }

            if (p != NULL)
            {
                free(p);
                p = NULL;
            }

            return L_OK;
        }

        pPrev = pNode;
        pNode = pNode->next;
    }

    return L_FAIL;
}

// 查找结点
LNode *nfind_node(LNode **table, int data)
{
    LNode *pNode = *table;
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

// 遍历链表
int ndisplay_list(LNode **table)
{
    printf("----------ndisplay----------\n");
    LNode *pNode = NULL;
    pNode = *table;
    while (pNode != NULL)
    {
        printf("%d\n", pNode->data);
        pNode = pNode->next;
    }

    return L_OK;
}

// 销毁链表
int ndestroy_list(LNode **table)
{
    LNode *pNode = *table;
    while (pNode != NULL)
    {
        LNode *pCur = pNode;
        pNode = pNode->next;

        if (pCur != NULL) 
        {
            free(pCur);
            pCur = NULL;
        }
    }

    *table = NULL;
    return L_OK;
}

// 计算表长
int nget_len(LNode **table)
{
    int len = 0;
    LNode *pNode = *table;
    while (pNode != NULL)
    {
        ++len;

        pNode = pNode->next;
    }

    return len;
}
