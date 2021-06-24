#include "stack.h"

int main()
{
    Stack stack;
    init_stack(&stack);

    if (S_OK == is_empty(&stack))
    {
        printf("stack empty!\n");
    }

    int data = 0;
    printf("-------push stack-------\n");
    scanf("%d", &data);
    while (S_OK == push_stack(&stack, data))
    {
        scanf("%d", &data);
    }

    if (S_OK == is_full(&stack))
    {
        printf("stack full!\n");
    }

    get_top(&stack, &data);
    printf("top = %d\n", data);

    printf("-------pop stack-------\n");
    while (S_OK == pop_stack(&stack, &data))
    {
        printf("pop = %d\n", data);
    }

    return S_OK;
}
