#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <stdlib.h>

#define H_FAIL -1
#define H_OK 0
#define HASH_SIZE 17777

// 数据结点定义
typedef struct HashNode
{
    int data;                     // 数据域
    struct HashNode *next;        // 指针域
}HashNode;

// 哈希表结构体定义
typedef struct HashSlot
{
    HashNode *head;               // 解决哈希冲突
}HashSlot;

// 初始化哈希表
int init_hash_table();

// 获取哈希键值
static int get_hash_key(int data);

// 插入数据
int insert_data(int data);

// 查找数据
int search_data(int data);

// 删除数据
int delete_data(int data);

// 遍历哈希表
int display_table();

// 销毁哈希表
int destroy_table();

#endif
