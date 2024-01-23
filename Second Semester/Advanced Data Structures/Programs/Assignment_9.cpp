#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string.h>
#define pow2(n) (1 << (n))
using namespace std;
struct Node
{
	string word;
	string definition;
	struct Node *l;
	struct Node *r;
	friend class AVL_Tree;
};

class AVL_Tree
{
public:
	Node *head;
	AVL_Tree()
	{
		head = new Node;
		head->l = NULL;
		head->r = NULL;
		head->definition = "AVL Dictionary";
		head->word = "Head";
	}

	int find_height(Node *t)
	{
		int h = 0;
		if (t != NULL)
		{
			int l_height = find_height(t->l);
			int r_height = find_height(t->r);
			int max_height = max(l_height, r_height);
			h = max_height + 1;
		}
		return h;
	}
	int find_difference(Node *t)
	{
		int l_height = find_height(t->l);
		int r_height = find_height(t->r);
		int b_factor = l_height - r_height;
		return b_factor;
	}
	Node *RR_rotation(Node *parent)
	{
		Node *t;
		t = parent->r;
		parent->r = t->l;
		t->l = parent;
		cout << "Right-Right Rotation Performed" << endl;
		return t;
	}
	Node *LL_rotation(Node *parent)
	{
		Node *t;
		t = parent->l;
		parent->l = t->r;
		t->r = parent;
		cout << "Left-Left Rotation Performed" << endl;
		return t;
	}
	Node *LR_rotation(Node *parent)
	{
		Node *t;
		t = parent->l;
		parent->l = RR_rotation(t);
		cout << "Left-Right Rotation Performed" << endl;
		return LL_rotation(parent);
	}
	Node *RL_rotation(Node *parent)
	{
		Node *t;
		t = parent->r;
		parent->r = LL_rotation(t);
		cout << "Right-Left Rotation Performed" << endl;
		return RR_rotation(parent);
	}
	Node *balance_AVL_Tree(Node *t)
	{
		int bal_factor = find_difference(t);
		if (bal_factor > 1)
		{
			if (find_difference(t->l) > 0)
				t = LL_rotation(t);
			else
				t = LR_rotation(t);
		}
		else if (bal_factor < -1)
		{
			if (find_difference(t->r) > 0)
				t = RL_rotation(t);
			else
				t = RR_rotation(t);
		}
		return t;
	}
	Node *insert_words(Node *r, string word, string definition)
	{
		if (r == NULL)
		{
			r = new Node;
			r->word = word;
			r->definition = definition;
			r->l = NULL;
			r->r = NULL;
			return r;
		}
		else if (strcmp(word.c_str(), r->word.c_str()) < 0)
		{
			r->l = insert_words(r->l, word, definition);
			r = balance_AVL_Tree(r);
		}
		else if (strcmp(word.c_str(), r->word.c_str()) >= 0)
		{
			r->r = insert_words(r->r, word, definition);
			r = balance_AVL_Tree(r);
		}
		return r;
	}
	void display_AVL_tree(Node *p, int l)
	{
		int i;
		if (p != NULL)
		{
			display_AVL_tree(p->r, l + 1);
			cout << endl;
			if (p == head)
				cout << "Root -> ";
			for (i = 0; i < l && p != head; i++)
				cout << endl;
			cout << p->word << ": " << p->definition << endl;
			display_AVL_tree(p->l, l + 1);
		}
	}
	void inorder_traversal(Node *t)
	{
		if (t == NULL)
			return;
		inorder_traversal(t->l);
		cout << t->word << " ";
		inorder_traversal(t->r);
	}
	void preorder_traversal(Node *t)
	{
		if (t == NULL)
			return;
		cout << t->word << " ";
		preorder_traversal(t->l);
		preorder_traversal(t->r);
	}
	void postorder_traversal(Node *t)
	{
		if (t == NULL)
			return;
		postorder_traversal(t->l);
		postorder_traversal(t->r);
		cout << t->word << " ";
	}
};

int main()
{
	int c, i;
	string word, definition;
	AVL_Tree avl;
	while (1)
	{
		cout << "1.Insert Element into the tree" << endl;
		cout << "2.show Balanced AVL Tree" << endl;
		cout << "3.InOrder traversal" << endl;
		cout << "4.PreOrder traversal" << endl;
		cout << "5.PostOrder traversal" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter your Choice: ";
		cout << endl
			 << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Enter the word to be inserted: ";
			cin >> word;
			cout << "Enter the definition of the word: ";
			cin >> definition;
			avl.head = avl.insert_words(avl.head, word, definition);
			break;
		case 2:
			if (avl.head == NULL)
			{
				cout << "Tree is Empty" << endl;
				continue;
			}
			cout << "Balanced AVL Tree:" << endl;
			avl.display_AVL_tree(avl.head, 1);
			cout << endl;
			break;
		case 3:
			cout << "Inorder Traversal:" << endl;
			avl.inorder_traversal(avl.head);
			cout << endl;
			break;
		case 4:
			cout << "Preorder Traversal:" << endl;
			avl.preorder_traversal(avl.head);
			cout << endl;
			break;
		case 5:
			cout << "Postorder Traversal:" << endl;
			avl.postorder_traversal(avl.head);
			cout << endl;
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}
