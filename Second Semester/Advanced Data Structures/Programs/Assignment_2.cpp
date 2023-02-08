#include <iostream>
#include <stack>

using namespace std;

class WordNode
{
    char data[10];
    WordNode *left;
    WordNode *right;
    friend class BinaryTree;
};

class BinaryTree
{
public:
    WordNode *root;
    BinaryTree()
    {
        root = NULL;
    }
    void create_root()
    {
        root = new WordNode;
        cout << "Enter the data: " << endl;
        cin >> root->data;
        root->left = NULL;
        root->right = NULL;
        create_recursive(root);
    }
    void create_recursive(WordNode *Node)
    {
        int choice = 0;
        WordNode *new_node;
        cout << "Enter if you want to enter a left node (1/0): "
             << "for the node -- " << Node->data << "-- ";
        cin >> choice;
        if (choice == 1)
        {
            new_node = new WordNode;
            cout << "Enter the data: ";
            cin >> new_node->data;
            Node->left = new_node;
            create_recursive(new_node);
        }
        cout << "Enter if you want to enter a right node (1/0): "
             << "for the node -- " << Node->data << "-- ";
        cin >> choice;
        if (choice == 1)
        {
            new_node = new WordNode;
            cout << "Enter the data: ";
            cin >> new_node->data;
            Node->right = new_node;
            create_recursive(new_node);
        }
    }

    void inorder_recursive(WordNode *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        inorder_recursive(temp->left);
        cout << temp->data << " ";
        inorder_recursive(temp->right);
    }
    void inorder_iterative(WordNode *temp)
    {
        if (!temp)
        {
            return;
        }

        stack<WordNode *> s;
        WordNode *current = temp;

        while (current != NULL || s.empty() == false)
        {
            while (current != NULL)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    void preorder_recursive(WordNode *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        cout << temp->data << " ";
        preorder_recursive(temp->left);
        preorder_recursive(temp->right);
    }
    void preorder_iterative(WordNode *temp)
    {
        if (!temp)
        {
            return;
        }

        stack<WordNode *> s;
        s.push(temp);

        while (s.empty() == false)
        {
            WordNode *current = s.top();
            cout << current->data << " ";
            s.pop();

            if (current->right)
            {
                s.push(current->right);
            }
            if (current->left)
            {
                s.push(current->left);
            }
        }
    }

    void postorder_recursive(WordNode *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        postorder_recursive(temp->left);
        postorder_recursive(temp->right);
        cout << temp->data << " ";
    }
    void postorder_iterative(WordNode *temp)
    {
        if (!temp)
        {
            return;
        }

        stack<WordNode *> s1;
        stack<WordNode *> s2;

        s1.push(temp);

        while (s1.empty() == false)
        {
            WordNode *current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left)
            {
                s1.push(current->left);
            }
            if (current->right)
            {
                s1.push(current->right);
            }
        }
        while (s2.empty() == false)
        {
            WordNode *current = s2.top();
            cout << current->data << " ";
            s2.pop();
        }
    }
};

int main()
{
    int choice = 0;
    BinaryTree main_tree;

    while (choice != 8)
    {
        cout << "\nWhat would like to do? " << endl;
        cout << "\n\nWelcome to ADS Assignment 2 - Binary Tree Traversals\n\nWhat would you like to do? " << endl;
        cout << "1. Create a Binary Tree"
             << endl;
        cout << "2. Traverse the Tree Inorder Recursively"
             << endl;
        cout << "3. Traverse the Tree Inorder Iteratively"
             << endl;
        cout << "4. Traverse the Tree PreOrder Recursively"
             << endl;
        cout << "5. Traverse the Tree PreOrder Iteratively"
             << endl;
        cout << "6. Traverse the Tree PostOrder Recursively"
             << endl;
        cout << "7. Traverse the Tree PostOrder Iteratively"
             << endl;
        cout << "8. Exit" << endl
             << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            main_tree.create_root();
            break;
        case 2:
            cout << "Traversing through the binary tree inorder recursively: " << endl;
            main_tree.inorder_recursive(main_tree.root);
            break;
        case 3:
            cout << "Traversing through the Binary Tree Inorder Iteratively: " << endl;
            main_tree.inorder_iterative(main_tree.root);
            break;
        case 4:
            cout << "Traversing through the Binary Tree PreOrder Recursively: " << endl;
            main_tree.preorder_recursive(main_tree.root);
            break;
        case 5:
            cout << "Traversing through the Binary Tree PreOrder Iteratively: " << endl;
            main_tree.preorder_iterative(main_tree.root);
            break;
        case 6:
            cout << "Traversing through the Binary Tree PostOrder Recursively: " << endl;
            main_tree.postorder_recursive(main_tree.root);
            break;
        case 7:
            cout << "Traversing through the Binary Tree PostOrder Iteratively: " << endl;
            main_tree.postorder_iterative(main_tree.root);
            break;
        case 8:
            cout << "Exiting the program" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}
