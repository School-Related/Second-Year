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
    bool isLeftNodeAThread;
    bool isRightNodeAThread;

public:
    ThreadedBinaryTreeNode()
    {
        left = NULL;
        right = NULL;
        isLeftNodeAThread = true;
        isRightNodeAThread = true;
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
        head->isLeftNodeAThread = false;
        head->isRightNodeAThread = false;
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
        head->isLeftNodeAThread = false;

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
                    if (temp->isLeftNodeAThread == true)
                    {
                        curr = new ThreadedBinaryTreeNode();
                        cout << "Enter the Data: ";
                        cin >> curr->data;
                        curr->right = temp;
                        temp->left = curr;
                        temp->isLeftNodeAThread = false;
                        flag = false;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else if (choice == 2)
                {
                    if (temp->isRightNodeAThread == true)
                    {
                        curr = new ThreadedBinaryTreeNode();
                        cout << "Enter the Data: ";
                        cin >> curr->data;
                        curr->left = temp;
                        curr->right = temp->right;
                        temp->right = curr;
                        temp->isRightNodeAThread = false;
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
            cout << temp->data << " ";
        }
    }
    ThreadedBinaryTreeNode *inorder_successor(ThreadedBinaryTreeNode *temp)
    {
        ThreadedBinaryTreeNode *x = temp->right;
        if (!temp->isRightNodeAThread) // right node a normal node? 
        {
            while (x->isLeftNodeAThread == false) // keep going left until you find a thread
                x = x->left;
        }
        return x;
    }

    void preorder_traversal()
    {
        ThreadedBinaryTreeNode *temp = head->left;
        while (temp != head)
        {
            cout << temp->data << " "; // V
            while (temp->isLeftNodeAThread == false) // while the left nodes are normal
            {
                temp = temp->left; // go left and print 
                cout << temp->data << " "; // L
            }
            while (temp->isRightNodeAThread == true) // while the right nodes are threads
            {
                temp = temp->right; // keep going right so you reach the parent once again
            }
            temp = temp->right; // once you reach the parent, go right so you can do the R from VLR
        }
    }
};

int main()
{
    ThreadedBinaryTree tree;
    tree.create();
    cout<<"The inorder traversal is:" << endl;
    tree.inorder_traversal();
    cout << endl;
    cout << "The preorder traversal is:" << endl;
    tree.preorder_traversal();
}
