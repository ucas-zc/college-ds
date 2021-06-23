#include "queue.h"

// 初始化队列
int init_queue(CyQueue *queue)
{
    // 异常判断
    if (queue == NULL)
    {
        return Q_FAIL;
    }

    queue->front = 0;
    queue->rear = 0;
    return Q_OK;
}

// 队列判空
int is_empty(CyQueue *queue)
{
    // 异常判断
    if (queue == NULL)
    {
        return Q_FAIL;
    }

    return queue->front == queue->rear ? Q_OK : Q_FAIL;
}

// 队列判满
int is_full(CyQueue *queue)
{
    // 异常判断
    if (queue == NULL)
    {
        return Q_FAIL;
    }

    return (queue->rear + 1) % MAX_SIZE == queue->front ? Q_OK : Q_FAIL;
}

// 入队
int push_queue(CyQueue *queue, int data)
{
    // 异常判断 | 队列满无法入队
    if (queue == NULL || Q_OK == is_full(queue))
    {
        return Q_FAIL;
    }

    queue->queue[queue->rear] = data;
    queue->rear = (queue->rear + 1) % MAX_SIZE;

    return Q_OK;
}

// 出队
int pop_queue(CyQueue *queue, int *data)
{
    // 异常判断 | 队列空无法出队，返回失败
    if (queue == NULL || Q_OK == is_empty(queue))
    {
        return Q_FAIL;
    }

    if (data != NULL)
    {
        *data = queue->queue[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
        return Q_OK;
    }

    return Q_FAIL;
}

// 计算队列长度
int get_len(CyQueue *queue)
{
    if (queue == NULL)
    {
        return Q_FAIL;
    }

    return (queue->rear + MAX_SIZE - queue->front) % MAX_SIZE;
}
