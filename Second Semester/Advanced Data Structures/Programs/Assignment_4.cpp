#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;

class ThreadedBinaryTreeNode
{
    string data;
    ThreadedBinaryTreeNode *left;
    ThreadedBinaryTreeNode *right;
    bool isLeftThread;
    bool isRightThread;

public:
    ThreadedBinaryTreeNode()
    {
        left = NULL;
        right = NULL;
        isLeftThread = true;
        isRightThread = true;
    }
    friend class ThreadedBinaryTree;
};

class ThreadedBinaryTree
{
public:
    ThreadedBinaryTreeNode *head;
    ThreadedBinaryTreeNode *root;
    ThreadedBinaryTree()
    {
        head = new ThreadedBinaryTreeNode();
        head->left = head;
        head->right = head;
        head->isLeftThread = true;
        head->isRightThread = true;
        root = NULL;
    }

    void create()
    {
        // Allocate memory for root;
        root = new ThreadedBinaryTreeNode();

        // Assign root->leftc and rightc to head;
        root->left = head;
        root->right = head;

        // Accept root data;
        cout << "Enter the root data: ";
        cin >> root->data;

        // Assign head lbit to 0;
        head->left = root;
        // Assign head->leftc to root;
        head->isLeftThread = false;

        ThreadedBinaryTreeNode *temp, *curr;
        temp = root;
        bool flag = true;
        int again = 0;
        int choice = 0;

        cout << "Do you want to enter another node? (1 or 0)" << endl;
        cin >> again;
        while (again != 0)
        {
            temp = root;
            flag = true;

            cout << "Enter 1 for Entering a new node to the Left, and 2 for Entering it to the right" << endl;
            cin >> choice;
            while (flag)
            {
                if (choice == 1)
                {
                    if (temp->isLeftThread == true)
                    {
                        curr = new ThreadedBinaryTreeNode();
                        cout << "Enter the Data: ";
                        cin >> curr->data;
                        curr->right = temp;
                        temp->left = curr;
                        temp->isLeftThread = false;
                        flag = false;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else if (choice == 2)
                {
                    if (temp->isRightThread == true)
                    {
                        curr = new ThreadedBinaryTreeNode();
                        cout << "Enter the Data: ";
                        cin >> curr->data;
                        curr->left = temp;
                        curr->right = temp->right;
                        temp->right = curr;
                        temp->isRightThread = false;
                        flag = false;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
            cout << "Do you want to enter another node? (1 or 0)" << endl;
            cin >> again;
        }
    }
    void inorder_traversal()
    {
        ThreadedBinaryTreeNode *temp;
        temp = head;
        while (true)
        {
            temp = inorder_successor(temp);
            if (temp == head)
                break;
            cout << temp->data;
        }
    }
    ThreadedBinaryTreeNode *inorder_successor(ThreadedBinaryTreeNode *temp)
    {
        ThreadedBinaryTreeNode *x = temp->right;
        if (temp->isRightThread)
        {
            while (x->isLeftThread)
                x = x->left;
        }
        return x;
    }

    void preorder_traversal()
    {
        ThreadedBinaryTreeNode *temp = head;
        while (temp != head)
        {
            cout << temp->data;
            while (temp->isLeftThread)
            {
                temp = temp->left;
                cout << temp->data;
            }
            while (temp->isRightThread)
            {
                temp = temp->right;
            }
            temp = temp->right;
        }
    }
};

int main()
{
    ThreadedBinaryTree tree;
    tree.create();
    tree.inorder_traversal();
    tree.preorder_traversal();
    cout << "done";
}