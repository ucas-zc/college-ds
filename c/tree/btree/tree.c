#include "tree.h"

// 树建立
TNode *build()
{
    int data = 0;
    scanf("%d", &data);
    if (data == 9999)
    {
        return NULL;
    }

    TNode *pNode = (TNode*)malloc(sizeof(TNode));
    if (pNode == NULL)
    {
        return NULL;
    }

    pNode->data = data;
    pNode->left = build();
    pNode->right = build();
    return pNode;
}

// 结点访问
static void visit(TNode *node)
{
    if (node != NULL)
    {
        printf("data: %d\n", node->data);
    }
}

// 先序遍历
int pre_order(TNode *root)
{
    if (root != NULL)
    {
        // 访问结点
        visit(root);
        pre_order(root->left);
        pre_order(root->right);
        return T_OK;
    }

    return T_FAIL;
}

// 中序遍历
int in_order(TNode *root)
{
    if (root != NULL)
    {
        in_order(root->left);
        // 访问结点
        visit(root);
        in_order(root->right);
        return T_OK;
    }

    return T_FAIL;
}

// 后序遍历
int post_order(TNode *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        // 访问结点
        visit(root);
        return T_OK;
    }

    return T_FAIL;

}


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
int push_queue(CyQueue *queue, TNode *data)
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
int pop_queue(CyQueue *queue, TNode **data)
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

// 层次遍历
int level_order(TNode *root)
{
    // 异常判断
    if (root == NULL)
    {
        return T_FAIL;
    }

    // 初始化队列
    CyQueue queue;
    init_queue(&queue);

    push_queue(&queue, root);
    // 根结点数据先入队
    while (Q_OK != is_empty(&queue))
    {
        TNode *temp;
        pop_queue(&queue, &temp);
        visit(temp);
        
        // 左结点数据入队
        if (temp->left != NULL)
        {
            push_queue(&queue, temp->left);
        }

        // 右结点数据入队
        if (temp->right != NULL)
        {
            push_queue(&queue, temp->right);
        }
    }

    return T_OK;
}
