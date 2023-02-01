#include <iostream>
#include <stack>

using namespace std;

class TreeNode
{
    char data[10];
    TreeNode *left;
    TreeNode *right;
    friend class BinaryTree;
};

class BinaryTree
{
public:
    TreeNode *root;
    BinaryTree()
    {
        root = NULL;
    }
    void create_root()
    {
        root = new TreeNode;
        cout << "Enter the data: " << endl;
        cin >> root->data;
        root->left = NULL;
        root->right = NULL;
        create_recursive(root);
    }
    void create_recursive(TreeNode *Node)
    {
        int choice = 0;
        TreeNode *new_node;
        cout << "Enter if you want to enter a left node (1/0): "
             << "for the node -- " << Node->data << "--" << endl;
        cin >> choice;
        if (choice == 1)
        {
            new_node = new TreeNode;
            cout << "Enter the data: " << endl;
            cin >> new_node->data;
            Node->left = new_node;
            create_recursive(new_node);
        }
        cout << "Enter if you want to enter a right node (1/0): "
             << "for the node -- " << Node->data << "--" << endl;
        cin >> choice;
        if (choice == 1)
        {
            new_node = new TreeNode;
            cout << "Enter the data: " << endl;
            cin >> new_node->data;
            Node->right = new_node;
            create_recursive(new_node);
        }
    }

    void inorder_recursive(TreeNode *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        inorder_recursive(temp->left);
        cout << temp->data << " ";
        inorder_recursive(temp->right);
    }
    void inorder_iterative(TreeNode *temp)
    {
        if (!temp)
        {
            return;
        }

        stack<TreeNode *> s;
        TreeNode *current = temp;

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

    void preorder_recursive(TreeNode *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        cout << temp->data << " ";
        preorder_recursive(temp->left);
        preorder_recursive(temp->right);
    }
    void preorder_iterative(TreeNode *temp)
    {
        if (!temp)
        {
            return;
        }

        stack<TreeNode *> s;
        s.push(temp);

        while (s.empty() == false)
        {
            TreeNode *current = s.top();
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

    void postorder_recursive(TreeNode *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        preorder_recursive(temp->left);
        preorder_recursive(temp->right);
        cout << temp->data << " ";
    }
    void postorder_iterative(TreeNode *temp)
    {
        if (!temp)
        {
            return;
        }

        stack<TreeNode *> s1;
        stack<TreeNode *> s2;

        s1.push(temp);

        while (s1.empty() == false)
        {
            TreeNode *current = s1.top();
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
    }
};

int main()
{
    int choice = 0;
    BinaryTree main_tree;

    while (choice != 11)
    {
        cout << "\nWhat would like to do? " << endl;
        cout << "\n\nWelcome to ADS Assignment 2 - Binary Tree Traversals\n\nWhat would you like to do? " << endl;
        cout << "1. Create a Binary Tree"
             << endl;
        cout << "2. Insert Elements to the Tree in Auto Ascending Order"
             << endl;
        cout << "3. Insert Elements to the Tree Level by Level"
             << endl;
        cout << "4. Insert Elements into the Tree Manually"
             << endl;
        cout << "5. Traverse the Tree Inorder Recursively"
             << endl;
        cout << "6. Traverse the Tree Inorder Iteratively"
             << endl;
        cout << "7. Traverse the Tree PreOrder Recursively"
             << endl;
        cout << "8. Traverse the Tree PreOrder Iteratively"
             << endl;
        cout << "9. Traverse the Tree PostOrder Recursively"
             << endl;
        cout << "10. Traverse the Tree PostOrder Iteratively"
             << endl;
        cout << "11. Exit" << endl
             << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            main_tree.create_root();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            cout << "Traversing through the binary tree inorder recursively: " << endl;
            main_tree.inorder_recursive(main_tree.root);
            break;
        case 6:
            cout << "Traversing through the Binary Tree Inorder Iteratively: " << endl;
            main_tree.inorder_iterative(main_tree.root);
            break;
        case 7:
            cout << "Traversing through the Binary Tree PreOrder Recursively: " << endl;
            main_tree.preorder_recursive(main_tree.root);
            break;
        case 8:
            cout << "Traversing through the Binary Tree PreOrder Iteratively: " << endl;
            main_tree.preorder_iterative(main_tree.root);
            break;
        case 9:
            cout << "Traversing through the Binary Tree PostOrder Recursively: " << endl;
            main_tree.postorder_recursive(main_tree.root);
            break;
        case 10:
            cout << "Traversing through the Binary Tree PostOrder Iteratively: " << endl;
            main_tree.postorder_iterative(main_tree.root);
            break;
        case 11:
            cout << "Exiting the program" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}
