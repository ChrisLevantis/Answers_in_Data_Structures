// This code makes the number in n, to the binary form in BCD
#include <stdio.h>
#include <stdlib.h>
#define MAX 4

struct Stack
{
    int maxSize;
    int top; // diktis stin korifi...
    int *stackArray;
};

struct Stack *createStack(int maxSize)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->maxSize = maxSize;
    stack->top = -1;
    stack->stackArray = (int *)malloc(sizeof(int) * stack->maxSize);

    return stack;
}

int isEmpty(struct Stack *stack)
{
    if (stack->top == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->maxSize - 1;
}

void push(struct Stack *stack, int dataInserted)
{
    if (isFull(stack))
    {
        return;
    }
    stack->top++;
    stack->stackArray[stack->top] = dataInserted;
}

int pop(struct Stack *stack)
{
    if (isEmpty == 0)
    {
        return -1;
    }
    else
    {
        int temp = stack->stackArray[stack->top];
        stack->top--;

        return temp;
    }
}

void peek(struct Stack *stack)
{
    if (isEmpty == 0)
    {
        return;
    }
    else
    {
        printf("PEEK --> %d\n", stack->stackArray[stack->top]);
    }
}

void myfunc(struct Stack *S, int n)
{
    while (n > 0)
    {
        push(S, n % 2);
        n = n / 2;
    }
    while (isEmpty(S) != 0)
        printf("%d ", pop(S));
}

int main()
{
    struct Stack *stack = createStack(4);

    myfunc(stack, 5);
    printf("\n");
}