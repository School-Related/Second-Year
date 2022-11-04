// Shop has item code, item name, quantity, and the cost.
// Input would be some item name, where we would first add things to the shop inventory
// Another option would be to check for the item in the database which is a list.
// If the item is found in the shop then you are supposed to ask them the number of items.
// if its available then you sell it, or else you tell them that that may items arent in stock.

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct Items
{
    int item_code;
    string item_name;
    int item_quantity;
    int item_cost;
    Items(int a, string b, int q, int c) : item_code(a), item_name(b), item_quantity(q), item_cost(c)
    {
    }
} currentItem(0, "", 0, 0), itemToAdd(0, "", 0, 0);

list<Items> items = {
    Items(101, "Burger", 10, 150),
    Items(102, "Fries", 10, 129),
    Items(103, "Ice Cream", 10, 40),
    Items(104, "Coke", 10, 50),
};

bool itemFound = false;
int currentItemCode = -1, currentItemIndex = -1;

void insertItems()
{
    cout << "Enter the details of the Item that you wanna enter to the database" << endl;
    cout << "Enter the Code of the new Item: ";
    cin >> itemToAdd.item_code;

    cout << "Enter the Name of the new Item: ";
    cin >> itemToAdd.item_name;

    cout << "Enter the Quantity of the new Item: ";
    cin >> itemToAdd.item_quantity;

    cout << "Enter the Cost of the new Item: ";
    cin >> itemToAdd.item_cost;

    items.push_back(itemToAdd);
    cout << "Item added successfully" << endl;
}

// returns true or false depending on whether the item was found, and if it was found, then it assigns
// it to the global struct object of current item, and assigns the variables currentItemCode, and currentItemIndex.
bool searchItem(int itemCode)
{
    int i = 0;
    for (list<Items>::iterator it = items.begin(); it != items.end(); it++, i++)
    {
        struct Items temp = *it;
        if (temp.item_code == itemCode)
        {
            currentItemCode = itemCode;
            currentItemIndex = i;
            currentItem = temp;
            return true;
        }
    }
    return false;
}

// just find the element at the element currentItemIndex, and replace it with the currentItem struct object.
void updateItems(int quantity)
{
    for (list<Items>::iterator it = items.begin(); it != items.end(); it++)
    {
        struct Items temp = *it;
        if (temp.item_code == currentItemCode)
        {
            currentItem.item_quantity -= quantity;
            items.erase(it);
            items.push_back(currentItem);
        }
    }
}
// display the things, and check if the selected item code by the user exists in the thing by calling searchItem. Then input the item quantity, check for it, and update the currentItem object.
// then call the updateItem function.
bool displayAndPurchaseItems()
{
    int selectedItemCode = -1;
    int selectedQuantity = 0;
    struct Items tempItem(0, "", 0, 0);
    cout << "The Items that you can buy are: " << endl;

    for (list<Items>::iterator it = items.begin(); it != items.end(); it++)
    {
        tempItem = *it;
        cout << tempItem.item_code << " " << tempItem.item_name << " " << tempItem.item_quantity << " " << tempItem.item_cost << endl;
    }
c:
    try
    {
        cout << "Please enter the code of the item that you wanna buy" << endl;
        cin >> selectedItemCode;
        if (!searchItem(selectedItemCode))
        {
            throw selectedItemCode;
        }
    l:
        cout
            << "Enter the Quantity of the Item that you wanna buy. "
            << endl;
        cout << "Max quantity is: " << currentItem.item_quantity << endl;
        cin >> selectedQuantity;
        try
        {
            if (selectedQuantity > currentItem.item_quantity)
            {
                throw selectedQuantity;
            }
            else
            {
                cout << "Thank you for Purchasing!" << endl;
                updateItems(selectedQuantity);
            }
        }
        catch (int something)
        {
            cout << "Quantity you entered is too much! Try again!" << endl;
            goto l;
        }
        return true;
    }
    catch (int something)
    {
        cout << "The code of the item that you entered doesnt exist. Try again. " << endl;
        goto c;
    }
    return true;
}

int main()
{
    int choice = 0;
    struct Items;
    cout << "Welcome to McRonalds" << endl;

    do
    {
        cout << endl
             << "What do you wanna do?\n\
        1. Add new Items\n\
        2. Purchase Item\n"
             << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertItems();
            break;
        case 2:
            if (!displayAndPurchaseItems())
            {
                cout << "Item couldnt be purchased!" << endl;
            }
            else
            {
                cout << "Item purchased and Updated Successfully" << endl;
            }
            // purchase item
            break;
        case 3:
            cout << "Thanks for Visiting our store!" << endl;
            break;
        default:
            cout << "Sorry, we cant do that in this store" << endl;
            break;
        }

        itemFound = false;
    } while (choice != 3);
    return 0;
}