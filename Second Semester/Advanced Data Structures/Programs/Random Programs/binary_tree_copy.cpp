#include <iostream>
#define MAX 10
using namespace std;
int top = -1;

class TreeNode
{
    public: 
        int value;
        TreeNode *left;
        TreeNode *right;
};

TreeNode *copy(TreeNode root)
{
    TreeNode temp = NULL;
    if(root != NULL){
        TreeNode temp = new TreeNode();
        temp.value = root.value;
        temp.left = copy(root.left);
        temp.right = copy(root.right);
    }
    return temp;
}

TreeNode * copy_nr(tree t2)
{
    // t2 is the original tree
    TreeNode temp1 = root;
    TreeNode temp2 = t2.root;
    copy_nr(temp1.value, temp2.value);
    while(1){
        
    }
}