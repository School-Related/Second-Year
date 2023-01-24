#include <iostream>
#define MAX 10
using namespace std;
int top = -1;

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *stack[MAX];

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
        return false;
}

bool isfull()
{
    if (top == MAX)
    {
        return true;
    }
    else
        return false;
}

void push(struct Node *value)
{
    stack[++top] = value;
}

struct Node *pop()
{
    if(!isEmpty())
        return stack[--top];
    else
        return NULL;
}

void inOrder_recursive(struct Node *root)
{
    if(root == NULL){
        return;
    }
    inOrder_recursive(root->left);
    cout << root->value << endl;
    inOrder_recursive(root->right);
}

void inOrder_iterative(struct Node *root)
{
}

void preOrder_recursive(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->value << endl;
    preOrder_recursive(root->left);
    preOrder_recursive(root->right);
}

void postOrder_recursive(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder_recursive(root->left);
    postOrder_recursive(root->right);
    cout << root->value << endl;
}

void preOrder_iterative(struct Node *root)
{
}

void postOrder_iterative(struct Node *root)
{
    struct Node *temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            push(temp);
            temp = temp->left;
        }
        if (stack[top]->right == NULL)
        {
            temp = pop();
            cout << temp->value << endl;
        }
        // while ()
    }
}

int main()
{

    return 0;
}