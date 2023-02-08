#include <iostream>
#include <queue>

using namespace std;

class threaded_bin_tree_node
{
public:
    int data;
    threaded_bin_tree_node *left;
    threaded_bin_tree_node *right;
    int lbit;
    int rbit;
    friend class threaded_bin_tree;
};

class threaded_bin_tree
{
public:
    threaded_bin_tree_node *root;
    threaded_bin_tree_node *head;
    threaded_bin_tree_node *curr;
    threaded_bin_tree_node *temp;

    threaded_bin_tree()
    {
        head = new threaded_bin_tree_node();
    }
    void create()
    {
        int flag = 0;
        root = new threaded_bin_tree_node();
        cout << "Enter the data for root: " << endl;
        root->left = head;
        root->right = head;
        head->left = root;

        do
        {
            flag = 0;
            temp = root;
            curr = new threaded_bin_tree_node();
            cout << "Enter data for the New Node: ";
        } while (true);
    }
    void inorder()
    {
        temp = head;
        while (true)
        {
            temp = inordersucc(temp);
            if (temp == head)
            {
                break;
            }
            cout << temp->data;
        }
    }

    threaded_bin_tree_node *inordersucc(temp)
    {
        x = new threaded_bin_tree_node();
        x = temp->right;
        if (temp->rbit == 0)
        {
            while (x.lbit == 0)
            {
                x = x.left;
            }
        }
        return x;
    }
    void preorder()
    {
        temp = head.left;
        while(temp != head){
            cout << temp->data;
            while(temp->lbit != 1){
                temp = temp->left;
                cout << temp->data;
            }
            while(temp->rbit == 1){
                
            }
        }
    }
    void postorder()
    {
    }
    void levelorder()
    {
    }
};

int main()
{

    return 0;
}
