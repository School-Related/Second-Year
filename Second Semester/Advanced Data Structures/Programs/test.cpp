// binary search tree inorder postorder preorder.

#include <iostream>
#include <stack>

using namespace std;

// we need to create the node class.

class Node
{
    int data;
    Node *left;
    Node *right;
    friend class Tree;

public:
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
}

// then antoher friend class of that node class, which then has functions for the actual thing that we are doing.
// this class will ahve have its own public variable for the node class, and we will use that throughout the functions.
// we will have constructors that will initialize values in both classes.
// the element that we usually have in the friend class is the root, which then directly points to the corresponding elements.

class Tree
{

public:
    Node *root;
    Tree()
    {
        root = new Node();
        root->left = NULL;
        root->right = NULL;
        cout << "Enter the Data for root" << endl;
        cin >> root->data;
        create(root);
    }

    // then there will be 2 create functions. A recursive function, and a worker functinos.

    void create(Node *node)
    {
        int choice = 1;
        cout << "The current node is: " << node->data;
        cout << "Do you wanna enter a left node or a right node? " << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "So you have chosen left" << endl;
            Node *temp = new Node();
            cout << "Enter data  ";
            cin >> temp->data;
            node->left = temp;
            create(temp);
        }
        else
        {
            cout << "So you have chosen right" << endl;
            Node *temp = new Node();
            cout << "Enter data  ";
            cin >> temp->data;
            node->right = temp;
            create(temp);
        }
    }

    // then you have the usual inorder, preorder and postorder ones. We will do both iterative, and recursive.

    void inorder(Node *temp)
    {
        // inorder iterative uses stack. Now the logic is clear, we know it is LVR. so the whole point of stack is that you dont wanna forget what node you visited, coz you might wanna visit its right child as well at some other point in time. So you might have to come back to it, and you would want to maintain the order in which you are visiting these nodes.
        // so stack we know works on the basis of last in first out. which is how we wanna traverse this thing.

        // safety check.
        if (!temp)
        {
            return;
        }

        // declare a stack.
        stack<Node *> s;

        // obviously we need a current pointer to actually read the contents of the stack, and put things inside it.
        Node *current = new Node();

        // now you need a stopping statement. when do we wanna stop this function? when we reach the end of the tree, that is the last child? no, at this point we wanna start tracing back. We wann stop when we visit everything, at which point the stack will be empty.

        while (current != NULL || s.empty() == false)
        {
            // now while current isnt null, we wanna keep going left. coz thats how we roll when going through the tree for inorder traversals, so we will just keep going left and left until we find no more left to go to.
            while (current != NULL)
            {
                s.push(current);
                current = current.left;
            }

            // at this point the stack is filled with some values, and we are at the left most end of the tree in other words, the L part of LVR is done, and now we need to do v
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;

            // now we repeat.
        }
    }
    void preorder(Node *temp)
    {
        // preorder is very similar.
        // except now we check only if s.empty is false. this in fact is easier.

        // its reallllly easy.
        while (s.empty() == false)
        {

            if (current.right)
            {
                s.push(current.right)
            }
            if (current.left)
            {
                s.push(current.left)
            }
        }
    }
    void postorder(Node *temp)
    {
    }

    void inorder_recursive(Node *temp)
    {
        // coz its a recursive function, we need to be able to provide a stopping statement.
        if (temp == NULL)
        {
            return;
        }
        inorder_recursive(temp->left);
        cout << temp->data << " ";
        inorder_recursive(temp->right);
    }
    void preorder_recursive(Node *temp)
    {
        // coz its a recursive statement, we gotta provide a ending statement.
        if (temp == NULL)
        {
            return;
        }
        cout << temp->data << " ";
        preorder_recursive(temp->left);
        preorder_recursive(temp->right);
    }
}

int
main()
{
    // make an object of the tree class, and then just call its functions.

    int choice = 0;
    Tree main_tree;

    while (choice != 4)
    {
        // display choices.

        cin >> choice;
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }
    }
}