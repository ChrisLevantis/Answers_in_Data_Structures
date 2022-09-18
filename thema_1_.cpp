/// OLOKLIROMENO
#include <iostream>
using namespace std;

struct Stack
{
    int maxSize;
    int top;
    int *stackArray;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->maxSize = capacity;
    stack->stackArray = (int*)malloc(sizeof(int) * stack->maxSize);
    stack->top = -1;

    return stack;
}

int isEmpty(struct Stack *stack)
{
    if(stack->top == -1)
    {
        return 0;
    }
    else
        return 1;
}

int isFull(struct Stack *stack)
{
    if(stack->top == stack->maxSize - 1)
    {
        return 0;
    }
    else
        return 1;
}

void push(struct Stack *stack, int dataInserted)
{
    if(isFull(stack) == 0)
    {
        cout << "Stack is Full!!!" << endl;
        return;
    }
    stack->top++;
    stack->stackArray[stack->top] = dataInserted;
    cout << "Element " << stack->stackArray[stack->top] << " has been pushed !! \n"; 
}

void pop(struct Stack *stack)
{
    if(isEmpty(stack) == 0)
    {
        cout << "Stack is Empty!!!" << endl;
        return;
    }
    cout << "Element " << stack->stackArray[stack->top] << " has been poped !! \n";
    stack->top--; 
}

void peek1(struct Stack *stack)
{
    if(isEmpty(stack) == 0)
    {
        cout << "Stack is Empty!!!" << endl;
        return;
    }
    cout << "Peek is --> " << stack->stackArray[stack->top] << endl;
}
int peek2(struct Stack *stack)
{
    if(isEmpty(stack) == 0)
    {
        cout << "Stack is Empty!!!" << endl;
        return -1;
    }
    return stack->stackArray[stack->top];
}

int main()
{
    int SIZE = 5;

    struct Stack *stack1 = createStack(SIZE);
    struct Stack *stack2 = createStack(SIZE);

    //push in the elements in the first stack
    push(stack1, 7);
    push(stack1, 9);
    push(stack1, 2);
    push(stack1, 4);
    push(stack1, 5);
/*
    5
    4
    2
    9
    7
*/

    printf("\nPEEK of Stack1\n");
    peek1(stack1); // 5
    cout << endl;

    // Trensfer all the elemnts from the stack1 to the stack2 so the only element that its gonna left in stack1 is 7...
    for(int i = 1;i <= SIZE - 1;i++)
    {
        push(stack2, peek2(stack1));
        pop(stack1);
        cout << endl;
    }

    printf("\n--AFTER THE TRANSFER-- \n");
    printf("\nPEEK of Stack1\n");
    peek1(stack1); // it must be 7

    printf("\nPEEK of Stack2\n");
    peek1(stack2); // it must be 9

        
    cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------------" <<  endl;
    pop(stack1); // now we popped 7 from stack1...
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" <<  endl;

    printf("\n--AFTER THE FINAL POPPED-- \n");
    printf("PEEK of Stack1\n");
    peek1(stack1); // it must be EMPTY

    // Trensfer all the elemnts from the stack2 back to the stack1...
    for(int i = 1;i <= SIZE - 1;i++)
    {
        push(stack1, peek2(stack2));
        pop(stack2);
        cout << endl;
    }


    printf("\n--AFTER THE FINAL TRANSFER-- \n");
    printf("\nPEEK of Stack1\n");
    peek1(stack1); // it must be 5

    printf("\nPEEK of Stack2\n");
    peek1(stack2); // it must be EMPTY
}