#include <iostream>
using namespace std;

class tbtnode
{
    char data;
    bool rbit;
    bool lbit;
    tbtnode *rightc;
    tbtnode *leftc;
    friend class tbt;

public:
    tbtnode();
};

tbtnode::tbtnode()
{
    lbit = 1;
    rbit = 1;
}

class tbt
{
    tbtnode *head;

public:
    tbt()
    {
        head = new tbtnode();
        head->lbit = 0;
        head->leftc = head->rightc = head;
        head->data = '#';
    }

    void create();
    void inorder();
    tbtnode *insuccr(tbtnode *temp);
};

void tbt::create()
{
    char ch;
    do
    {
        int flag = 0;
        tbtnode *temp = head;
        tbtnode *curr = new tbtnode();

        cout << "Enter data for the node: ";
        cin >> curr->data;

        while (flag == 0)
        {
            cout << "Enter choice - l/r for left/right of " << temp->data << ": ";
            char ch1;
            cin >> ch1;

            if (ch1 == 'l')
            {
                if (temp->lbit == 1)
                {
                    curr->rightc = temp;
                    curr->leftc = temp->leftc;
                    temp->leftc = curr;
                    temp->lbit = 0;
                    flag = 1;
                }
                else
                    temp = temp->leftc;
            }
            else if (ch1 == 'r')
            {
                if (temp->rbit == 1)
                {
                    curr->leftc = temp;
                    curr->rightc = temp->rightc;
                    temp->rightc = curr;
                    temp->rbit = 0;
                    flag = 1;
                }
                else
                    temp = temp->rightc;
            }
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> ch;

    } while (ch == 'y');
}

void tbt::inorder()
{
    tbtnode *temp = head->leftc;

    while (temp != head)
    {
        while (temp->lbit == 0)
            temp = temp->leftc;

        cout << temp->data << " ";

        while (temp->rbit == 1)
        {
            temp = temp->rightc;
            if (temp == head)
                return;
            cout << temp->data << " ";
        }

        temp = temp->rightc;
    }
}

tbtnode *tbt::insuccr(tbtnode *temp)
{
    if (temp->rbit == 1)
        return temp->rightc;
    else
    {
        temp = temp->rightc;
        while (temp->lbit == 0)
            temp = temp->leftc;
        return temp;
    }
}

int main()
{
    tbt T;
    T.create();
    cout << "Inorder traversal of the threaded binary tree: ";
    T.inorder();
    return 0;
}