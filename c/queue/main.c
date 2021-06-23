#include "queue.h"

int main()
{
    // 初始化队列
    CyQueue queue;
    init_queue(&queue);

    // 判队列空
    int ret = is_empty(&queue);
    if (ret == Q_OK)
    {
        printf("queue empty\n");
    }

    // 循环入队
    int data = 0;
    scanf("%d", &data);
    while (Q_OK == push_queue(&queue, data))
    {
        scanf("%d", &data);
    }

    // 判队列满
    ret = is_full(&queue);
    if (ret == Q_OK)
    {
        printf("queue full\n");
    }

    printf("len = %d\n", get_len(&queue));

    // 出队
    while (Q_OK == pop_queue(&queue, &data))
    {
        printf("pop = %d\n", data);
    }

    return Q_OK;
}
