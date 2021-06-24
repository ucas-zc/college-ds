#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>

#define Q_OK 0
#define Q_FAIL -1
#define MAX_SIZE 128

// 队列顺序存储结构体定义
typedef struct Cycle_Queue
{
    int queue[MAX_SIZE];                    // 队列，类型可根据需求改变
    int front;                              // 对头下标
    int rear;                               // 队尾下标
}CyQueue;

// 队列初始化
int init_queue(CyQueue *queue);

// 队列判空
int is_empty(CyQueue *queue);

// 队列判满
int is_full(CyQueue *queue);

// 入队
int push_queue(CyQueue *queue, int data);

// 出队
int pop_queue(CyQueue *queue, int *data);

// 计算队列长度
int get_len(CyQueue *queue);

#endif
