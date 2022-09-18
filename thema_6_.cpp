/// OLOKLIROMENO
#include <iostream>
using namespace std;

struct TreeNode
{
    char data;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
};

// It creates a Node 
/// @brief
/// @param dataInserted
struct TreeNode *createTree(char dataInserted)
{
    struct TreeNode *new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new_node->data = dataInserted;

    new_node->leftChild = NULL;
    new_node->rightChild = NULL;

    return new_node;
}

/// @brief 
/// @param root 
/// @return 
int treeHeight(struct TreeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left_height = treeHeight(root->leftChild);
    int right_height = treeHeight(root->rightChild);

    int max;
    if(left_height > right_height)
        max = left_height;
    else if(right_height > left_height)
        max = right_height;
    else // if we reach this els, there is no difference bettween right and left height
        max = right_height;

    return max + 1;
}

/// @brief 
/// @param root 
/// @param level_no 
void printInLevel(struct TreeNode *root, int level_no)
{
    if(root == NULL)
        return;
    else if(level_no == 0) // that means we are in the root node... 
    {
        cout << root->data;
    }
    else
    {
        printInLevel(root->leftChild, level_no - 1);
        printInLevel(root->rightChild, level_no - 1);   
    }
}

// By-Level traversal
/// @brief 
/// @param root 
void by_level(struct TreeNode *root)
{
    if(root == NULL)
    {
        cout << "Opps Empty Tree" << endl;
        return;
    }
    for(int i = 0;i < treeHeight(root);i++)
    {
        printInLevel(root, i);
        cout << endl;
    }
}

// InOrder traversal
/// @brief 
/// @param root 
void inOrder(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->leftChild);
    printf("%c ", root->data);
    inOrder(root->rightChild);
}

int main()
{
    struct TreeNode *root = createTree('A');

    // Build left SUB-TREE
    root->leftChild = createTree('B');
    root->leftChild->leftChild = createTree('D');
    root->leftChild->rightChild = createTree('E');
    root->leftChild->rightChild->leftChild = createTree('H');
    root->leftChild->rightChild->leftChild->leftChild = createTree('L');
    root->leftChild->rightChild->leftChild->rightChild = createTree('M');

    root->rightChild = createTree('C');
    root->rightChild->leftChild = createTree('F');
    root->rightChild->leftChild->leftChild = createTree('I');
    root->rightChild->leftChild->rightChild = createTree('J');
    root->rightChild->rightChild= createTree('G');
    root->rightChild->rightChild->rightChild = createTree('K');
    root->rightChild->rightChild->rightChild->leftChild = createTree('N');
    root->rightChild->rightChild->rightChild->rightChild = createTree('C');

    /*
               A
             /  \
            B    C
           / \  / \
          D  E  F  G
            /  / \  \ 
           H  I   J  K 
          / \       /  \
          L  M     N    C
    */

   cout << "\nHEIGHT OF THE TREE IS --> " << treeHeight(root) << endl; // 5

   cout << "\nPrint in Level-Order\n";
   by_level(root);

   cout << "\nPrint inOrder\n";
   inOrder(root);
   cout << endl;
}   