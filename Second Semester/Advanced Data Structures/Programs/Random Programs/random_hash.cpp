/*
 * assign2
 *
 *  Created on: 23-Jan-2023
 *  Author: Gyanendra Tiwari
 *  Topic: Binary Tree Creation Recursive
 */
#include <iostream>
#include <stack>

using namespace std;

class treenode // creating class for nodes of tree which contains the node info
{
    char data[10];
    treenode *left;
    treenode *right;
    friend class tree;
};

class tree // friend class of treenode which will be used to make a new tree
{
    treenode *root;

public:
    tree();
    void create_r();
    void create_r(treenode *);
    void pre_order();
    void in_order();
    void post_order();
    void pre_order(treenode *);
    void in_order(treenode *);
    void post_order(treenode *);
};

void tree::create_r() // driver for creation
{
    root = new treenode;
    cout << "\nPlease Enter Data for root: ";
    cin >> root->data;
    create_r(root);
}

void tree::create_r(treenode *temp)
{
    char choice;
    treenode *curr;
    cout << "Do you want to add data to the left " << temp->data << " y/n ?\n";
    cin >> choice;
    if (choice == 'y')
    {

        curr = new treenode;
        cout << "\nData: ";
        cin >> curr->data;
        temp->left = curr;
        create_r(curr);
    }
    cout << "do you want to add data to the right " << temp->data << " y/n ?\n";
    cin >> choice;
    if (choice == 'y')
    {
        curr = new treenode;
        cout << "\nData: ";
        cin >> curr->data;
        temp->right = curr;
        create_r(curr);
    }
}

void tree::in_order()
{
    in_order(root);
}

void tree::pre_order()
{
    pre_order(root);
}

void tree::post_order()
{
    post_order(root);
}

void tree::in_order(treenode *temp)
{

    if (temp != NULL)
    {
        in_order(temp->left);
        cout << temp->data << " ";
        in_order(temp->right);
    }
}

void tree::pre_order(treenode *temp)
{

    if (temp != NULL)
    {
        cout << temp->data << " ";
        pre_order(temp->left);
        pre_order(temp->right);
    }
}

void tree::post_order(treenode *temp)
{

    if (temp != NULL)
    {
        post_order(temp->left);
        post_order(temp->right);
        cout << temp->data << " ";
    }
}

int main()
{

    tree bt;
    bt.create_r();
    int select;

    cout << "\nSelect the Mode for Displaying\n1. Inorder\n2. Preorder\n3. Postorder\n Type Here: ";
    cin >> select;

    switch (select)
    {
    case 1:
        cout << "\nInorder: ";
        bt.in_order();
        break;
    case 2:
        cout << "\nPreorder: ";
        bt.pre_order();
        break;
    case 3:
        cout << "\nPostorder: ";
        bt.post_order();
        break;

    default:
        cout << "\nWrong Choice";
    }

    return 0;
}

tree::tree()
{
    root = NULL;
}