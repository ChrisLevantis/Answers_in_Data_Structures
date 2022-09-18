/// OLOKLIROMENO
#include <iostream>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

/// @brief
/// @param head
/// @param dataInserted
void insert_FrontIfEmpty_Rear(struct Node **head, int dataInserted)
{
    if (*head == NULL) // empty list...
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->value = dataInserted;

        *head = new_node;
        new_node->next = NULL;
        return;
    }
    else // if its not empty...NOTE --> HERE WE GONNA INSERT IN THE END...
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->value = dataInserted;
        new_node->next = NULL; // its gonna be the last node so the next of it is NULL...

        struct Node *last = *head; // pointer to the last node of the list...
        while (last->next != NULL) // when it gets out of this while loop last is gonna be in the last node...
        {
            last = last->next;
        }

        last->next = new_node;
        return;
    }
}

/// @brief
/// @param head
/// @param dataInserted
void insertStart(struct Node **head, int dataInserted)
{
    if (*head == NULL)
    {
        cout << "Opps is empty, lets call the correct func which is **insert_FrontIfEmpty_Rear**" << endl;
        insert_FrontIfEmpty_Rear(*(&head), dataInserted);
        return;
    }
    else
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->value = dataInserted;

        new_node->next = *head;
        *head = new_node;

        return;
    }
}

/// @brief
/// @param head
/// @param dataToFind
/// @param dataInserted
void insertAfter(struct Node **head, int dataToFind, int dataInserted)
{
    if (*head == NULL)
    {
        cout << "Opps is empty, lets call the correct func which is **insert_FrontIfEmpty_Rear**" << endl;
        insert_FrontIfEmpty_Rear(*(&head), dataInserted);
        return;
    }
    else
    {
        // Find the node with the value in dataToFind
        struct Node *prev = *head;
        while (prev->next != NULL)
        {
            if (prev->value == dataToFind)
            {
                break;
            }
            prev = prev->next;
        }

        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->value = dataInserted;

        new_node->next = prev->next;
        prev->next = new_node;
        return;
    }
}

/// print backwards the list
/// @brief 
/// @param head 
void myfunc(struct Node *head)
{
    if (head == NULL)
        return;
    myfunc(head->next);
    printf("%d ", head->value);
}

/// @brief
/// @param n
void printList(struct Node *n)
{
    if (n == NULL)
    {
        printf("Empty List...(in print)\n");
        return;
    }
    while (n != NULL)
    {
        cout << n->value << " ";
        n = n->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    cout << "CALLING **insert_FrontIfEmpty_Rear**" << endl;
    insert_FrontIfEmpty_Rear(&head, 3);
    insert_FrontIfEmpty_Rear(&head, 99);
    insert_FrontIfEmpty_Rear(&head, 12);
    insert_FrontIfEmpty_Rear(&head, 899);
    printList(head);

    cout << "\nCALLING **insertStart**" << endl;
    insertStart(&head, 3333);
    insertStart(&head, 6565);
    printList(head);

    cout << "\nCALLING **insertAfter**" << endl;
    insertAfter(&head, 99, 6969);
    printList(head);

    cout << "\nCALLING **myfunc**" << endl;
    myfunc(head); // print backwards the list...
    cout << endl;
}