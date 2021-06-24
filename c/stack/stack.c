#include "stack.h"

// 初始化栈
int init_stack(Stack *stack)
{
    // 异常判断
    if (stack == NULL)
    {
        return S_FAIL;
    }

    // 栈顶下标置0
    stack->top = -1;
    return S_OK;
}

// 判空
int is_empty(Stack *stack)
{
    // 异常判断
    if (stack == NULL)
    {
        return S_FAIL;
    }

    return stack->top == -1 ? S_OK : S_FAIL;
}

// 判满
int is_full(Stack *stack)
{
    // 异常判断
    if (stack == NULL)
    {
        return S_FAIL;
    }

    return stack->top == MAX_SIZE - 1 ? S_OK : S_FAIL;
}

// 入栈
int push_stack(Stack *stack, int data)
{
    // 异常判断 | 栈满不入栈
    if (stack == NULL || S_OK == is_full(stack))
    {
        return S_FAIL;
    }

    stack->stack[++stack->top] = data;
    return S_OK;
}

// 出栈
int pop_stack(Stack *stack, int *data)
{
    // 异常判断 | 栈空不出栈
    if (stack == NULL || S_OK == is_empty(stack))
    {
        return S_FAIL;
    }

    if (data != NULL)
    {
        *data = stack->stack[stack->top--];
        return S_OK;
    }

    return S_FAIL;
}

// 获取栈顶元素
int get_top(Stack *stack, int *data)
{
    // 异常判断 | 栈空不出栈
    if (stack == NULL || S_OK == is_empty(stack))
    {
        return S_FAIL;
    }

    if (data != NULL)
    {
        *data = stack->stack[stack->top];
        return S_OK;
    }

    return S_FAIL;
}
