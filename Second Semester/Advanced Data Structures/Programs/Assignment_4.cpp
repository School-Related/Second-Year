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
    bool isRrightThread;

public:
    ThreadedBinaryTreeNode()
    {
        left = NULL;
        right = NULL;
        isLeftThread = false;
        isRrightThread = false;
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
        head->isRrightThread = true;
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
        bool flag = true, again = true;
        int choice = 0;
     
        cout << "Do you want to enter another node? (1 or 0)" << endl;
        cin >> again;
        while (again != 0 || again != false)
        {
            while (flag)
            {
                cout << "Enter 1 for Entering a new node to the Left, and 2 for Entering it to the right" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    if (temp->isLeftThread == false)
                    {
                        curr = new ThreadedBinaryTreeNode();
                        cout << "Enter the Data: ";
                        cin >> curr->data;
                        curr->left = temp;
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
                    if (temp->isRrightThread == false)
                    {
                        curr = new ThreadedBinaryTreeNode();
                        cout << "Enter the Data: ";
                        cin >> curr->data;
                        curr->right = temp;
                        temp->right = curr;
                        temp->isRrightThread = false;
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
    ThreadedBinaryTreeNode* inorder_successor(ThreadedBinaryTreeNode *temp)
    {
        ThreadedBinaryTreeNode *x = temp->right;
        if (temp->isLeftThread == 0)
        {
            while (x->isLeftThread == 0)
                x = x->left;
        }
        return x;
    }
};

int main(){
    ThreadedBinaryTree tree;
    tree.create();
    tree.inorder_traversal();
    // ThreadedBinaryTreeNode a;
    cout << "done";
}