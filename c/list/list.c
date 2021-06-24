#include "list.h"

// 头插法建立单链表(带头结点)
int head_insert(LNode *head)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    int data;
    scanf("%d", &data);
    while (data != 9999)
    {
        LNode *pNode = (LNode*)malloc(sizeof(LNode));
        if (NULL == pNode) {
            return L_FAIL;
        }

        pNode->data = data;
        pNode->next = head->next;
        head->next = pNode;

        scanf("%d", &data);
    }

    return L_OK;
}

// 尾插法
int tail_insert(LNode *head)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    int data;
    scanf("%d", &data);
    LNode *pTail = head;
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

// 中间插入结点
int insert_data(LNode *head, int data, int pos_data)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    LNode *pNode = NULL;
    pNode = head->next;
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
int delete_data(LNode *head, int data)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    LNode *pPrev = head;
    LNode *pNode = head->next;
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
LNode *find_node(LNode *head, int data)
{
    // 异常判断
    if (head == NULL)
    {
        return NULL;
    }

    LNode *pNode = head->next;
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
int display_list(LNode *head)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    printf("----------display----------\n");
    LNode *pNode = NULL;
    pNode = head->next;
    while (pNode != NULL)
    {
        printf("%d\n", pNode->data);
        pNode = pNode->next;
    }

    return L_OK;
}

// 销毁链表
int destroy_list(LNode *head)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    LNode *pNode = head->next;
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

    head->next = NULL;
    return L_OK;
}

// 计算表长
int get_len(LNode *head)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    int len = 0;
    LNode *pNode = head->next;
    while (pNode != NULL)
    {
        ++len;

        pNode = pNode->next;
    }

    return len;
}

// 头插法建立单链表(不带头结点)
int nhead_insert(LNode **head)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    int data;
    scanf("%d", &data);
    if (data == 9999)
    {
        return L_OK;
    }

    *head = (LNode *)malloc(sizeof(LNode));
    (*head)->data = data;
    (*head)->next = NULL;

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
        pNode->next = *head;
        *head = pNode;
    }

    return L_OK;
}

// 尾插法建立单链表(不带头结点)
int ntail_insert(LNode **head)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    int data;
    scanf("%d", &data);
    if (data == 9999)
    {
        return L_OK;
    }

    *head = (LNode *)malloc(sizeof(LNode));
    (*head)->data = data;
    (*head)->next = NULL;

    LNode *pTail = *head;

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
int ninsert_data(LNode **head, int data, int pos_data)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    LNode *pNode = NULL;
    pNode = *head;
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
int ndelete_data(LNode **head, int data)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    LNode *pPrev = NULL;
    LNode *pNode = *head;
    while (pNode != NULL)
    {
        if (pNode->data == data)
        {
            LNode *p = pNode;
            if (pPrev == NULL)
            {
                *head = pNode->next;
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
LNode *nfind_node(LNode **head, int data)
{
    // 异常判断
    if (head == NULL)
    {
        return NULL;
    }

    LNode *pNode = *head;
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
int ndisplay_list(LNode **head)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    printf("----------ndisplay----------\n");
    LNode *pNode = NULL;
    pNode = *head;
    while (pNode != NULL)
    {
        printf("%d\n", pNode->data);
        pNode = pNode->next;
    }

    return L_OK;
}

// 销毁链表
int ndestroy_list(LNode **head)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    LNode *pNode = *head;
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

    *head = NULL;
    return L_OK;
}

// 计算表长
int nget_len(LNode **head)
{
    // 异常判断
    if (head == NULL)
    {
        return L_FAIL;
    }

    int len = 0;
    LNode *pNode = *head;
    while (pNode != NULL)
    {
        ++len;

        pNode = pNode->next;
    }

    return len;
}
