#include "hash.h"

// 哈希表
static HashSlot *hash_table;

// 初始化哈希表
int init_hash_table()
{
    // 给哈希表分配内存
    hash_table = (HashSlot*)malloc(HASH_SIZE * sizeof(HashSlot));
    if (hash_table == NULL)
    {
        return H_FAIL;
    }

    int index = 0;
    for (; index < HASH_SIZE; ++index)
    {
        hash_table[index].head = (HashNode*)malloc(sizeof(HashNode));
        if (hash_table[index].head == NULL)
        {
            return H_FAIL;
        }

        hash_table[index].head->next = NULL;
    }

    return H_OK;
}

// 获取哈希键值
static int get_hash_key(int data)
{
    return data < 0 ? (-data % HASH_SIZE) : (data % HASH_SIZE);
}

// 插入一个数据
int insert_data(int data)
{
    // 获取hash键值
    int key = get_hash_key(data);
    if (key < 0)
    {
        return H_FAIL;
    }

    // 哈希槽不为空
    if (hash_table != NULL)
    {
        HashNode *temp = (HashNode*)malloc(sizeof(HashNode));
        if (temp == NULL)
        {
            return H_FAIL;
        }

        // 头插法插入数据
        temp->data = data; 
        temp->next = hash_table[key].head->next;
        hash_table[key].head->next = temp;

        return H_OK;
    }

    return H_FAIL;
}

// 查找一个数据
int search_data(int data)
{
    // 获取hash键值
    int key = get_hash_key(data);
    if (key < 0)
    {
        return H_FAIL;
    }

    // 获取哈希槽内的链表头
    if (hash_table != NULL)
    {
        HashNode *temp = hash_table[key].head->next;
        while (temp != NULL)
        {
            if (data == temp->data)
            {
                printf("search success: %d\n", temp->data);
                return H_OK;
            }

            temp = temp->next;
        }
    }

    return H_FAIL;
}

int delete_data(int data)
{
    // 获取hash键值
    int key = get_hash_key(data);
    if (key < 0)
    {
        return H_FAIL;
    }

    // 获取哈希槽内的链表头
    if (hash_table != NULL)
    {
        HashNode *prev = hash_table[key].head;
        HashNode *temp = hash_table[key].head->next;
        while (temp != NULL)
        {
            if (data == temp->data)
            {
                printf("delete success: %d\n", temp->data);
                prev->next = temp->next;
                temp->next = temp;

                if (temp != NULL)
                {
                    free(temp);
                    temp = NULL;
                }
                return H_OK;
            }

            prev = prev->next;
            temp = temp->next;
        }
    }

    return H_FAIL;
}

// 遍历哈希表
int display_table()
{
    // 哈希表空返回失败
    if (hash_table == NULL)
    {
        return H_FAIL;
    }

    int index = 0;
    for (; index < HASH_SIZE; ++index)
    {
        HashNode *temp = hash_table[index].head->next;
        if (temp == NULL)
        {
            continue;
        }

        printf("-----------hash slot: %d------------\n", index);
        while (temp != NULL)
        {
            printf("data: %d\n", temp->data);
            temp = temp->next;
        }
    }

    return H_OK;
}

// 销毁哈希表
int destroy_table()
{
    // 哈希表空返回失败
    if (hash_table == NULL)
    {
        return H_FAIL;
    }

    int index = 0;
    for (; index < HASH_SIZE; ++index)
    {
        HashNode *temp = hash_table[index].head->next;
        if (temp == NULL)
        {
            continue;
        }

        while (temp != NULL)
        {
            HashNode *p = temp;
            hash_table[index].head->next = temp->next;
            temp = temp->next;

            p->next = p;
            if (p != NULL)
            {
                free(p);
                p = NULL;
            }
        }
    }

    free(hash_table);
    hash_table = NULL;

    return H_OK;
}
