/// OLOKLIROMENO
#include <iostream>
using namespace std;

struct Stack
{
    int maxSize;
    int top;
    char *stackArray;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->maxSize = capacity;
    stack->stackArray = (char *)malloc(sizeof(char) * stack->maxSize);
    stack->top = -1;

    return stack;
}

int isEmpty(struct Stack *stack)
{
    if (stack->top == -1)
    {
        return 0;
    }
    else
        return 1;
}

int isFull(struct Stack *stack)
{
    if (stack->top == stack->maxSize - 1)
    {
        return 0;
    }
    else
        return 1;
}

void push(struct Stack *stack, int dataInserted)
{
    if (isFull(stack) == 0)
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
    if (isEmpty(stack) == 0)
    {
        cout << "Stack is Empty!!!" << endl;
        return;
    }
    cout << "Element " << stack->stackArray[stack->top] << " has been poped !! \n";
    stack->top--;
}
int peek(struct Stack *stack)
{
    if (isEmpty(stack) == 0)
    {
        cout << "Stack is Empty!!!" << endl;
        return -1;
    }
    return stack->stackArray[stack->top];
}
///////////////////////////////////////////////////////////////////////////////////
int check(char ch, struct Stack *stack)
{
    if (ch == '[' || ch == '(' || ch == '{')
    {
        push(stack, ch);
    }
    else if (ch == ']')
    {
        if (peek(stack) == '[')
            pop(stack); 
        else
            return -1;
    }
    else if (ch == ')')
    {
        if (peek(stack) == '(')
            pop(stack);
        else
            return -1;
    }
    else if (ch == '}')
    {
        if (peek(stack) == '{')
            pop(stack);
        else
            return -1;
    }
    return 1;
}

int main()
{
    struct Stack *stack = createStack(10);

    //string str = "([)]";
    string str = "([{}])()";
    //string str = "()[]{}(())";

    int temp;
    for (int i = 0; i < str.size(); i++)
    {
        temp = check(str[i], stack);

        if(temp == -1)
            break;
    }

    if(temp == 1)
    {
        cout << "\nOLA KOMPLE\n";
    }
    else if(temp == -1)
    {
        cout << "\nDEN EINAI KOMPLE\n";
    }
}
