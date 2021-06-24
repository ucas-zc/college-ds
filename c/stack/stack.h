#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>

#define S_OK 0
#define S_FAIL -1
#define MAX_SIZE 5

// 栈顺序存储结构定义
typedef struct Stack
{
    int stack[MAX_SIZE];                       // 栈，类型可改变
    int top;                                   // 栈顶元素下标
}Stack;

// 栈初始化
int init_stack(Stack *stack);

// 栈判空
int is_empty(Stack *stack);

// 栈判满
int is_full(Stack *stack);

// 入栈
int push_stack(Stack *stack, int data);

// 出栈
int pop_stack(Stack *stack, int *data);

// 获取栈顶元素
int get_top(Stack *stack, int *data);

#endif
