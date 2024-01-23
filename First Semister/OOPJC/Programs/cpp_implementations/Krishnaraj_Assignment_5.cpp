// Shop has item code, item name, quantity, and the cost.
// Input would be some item name, where we would first add things to the shop inventory
// Another option would be to check for the item in the database which is a list.
// If the item is found in the shop then you are supposed to ask them the number of items.
// if its available then you sell it, or else you tell them that that may items arent in stock.

#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

void binary_search(){
    
}


// struct so we can put it in a single linked list.
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

// linked list items so we can put objects of structures in it easily.
list<Items> items = {
    Items(101, "Burger", 10, 200),
    Items(102, "Fries", 10, 129),
    Items(103, "Ice Cream", 10, 40),
    Items(104, "Coke", 10, 50),
};

bool itemFound = false;
// returns true or false depending on whether the item was found
bool searchItem(int itemCode)
{
    int i = 0;
    for (list<Items>::iterator it = items.begin(); it != items.end(); it++, i++)
    {
        struct Items temp = *it;
        if (temp.item_code == itemCode)
        {
            currentItem = temp;
            return true;
        }
    }
    return false;
}

// inserts items in the list
void insertItems()
{
    cout << "Enter the details of the Item that you wanna enter to the database" << endl;
i:
    cout << "Enter the Code of the new Item: ";
    cin >> itemToAdd.item_code;
    if (searchItem(itemToAdd.item_code))
    {
        cout << "Item already exists, try another code!" << endl;
        goto i;
    }
    cout << "Enter the Name of the new Item: ";
    cin >> itemToAdd.item_name;

    cout << "Enter the Quantity of the new Item: ";
    cin >> itemToAdd.item_quantity;

    cout << "Enter the Cost of the new Item: ";
    cin >> itemToAdd.item_cost;

    items.push_back(itemToAdd);
    cout << "Item added successfully" << endl;
}

// just find the element at the element currentItemIndex, and replace it with the currentItem struct object.
void updateItems(int updatedItemcost, int updatedQuantity, int currentItemCode)
{
    for (list<Items>::iterator it = items.begin(); it != items.end(); it++)
    {
        struct Items temp = *it;
        if (temp.item_code == currentItemCode)
        {
            currentItem.item_quantity = updatedQuantity;
            currentItem.item_cost = updatedItemcost;
            items.erase(it);
            items.push_back(currentItem);
        }
    }
}

// just displays the items in a table nicely
void displayItems()
{
    struct Items tempItem(0, "", 0, 0);
    cout << "The Items that you can buy are: " << endl;

    cout << setw(20) << "ITEM CODE" << setw(20) << "ITEM NAME" << setw(20) << "ITEM QUANTITY" << setw(20) << "ITEM COST" << endl;
    for (list<Items>::iterator it = items.begin(); it != items.end(); it++)
    {
        tempItem = *it;
        cout << setw(20) << tempItem.item_code << setw(20) << tempItem.item_name << setw(20) << tempItem.item_quantity << setw(20) << tempItem.item_cost << endl;
    }
}

// display the things, and check if the selected item code by the user exists in the thing by calling searchItem. Then input the item quantity, check for it, and update the currentItem object.
// then call the updateItem function.
bool PurchaseItems()
{
    int selectedItemCode = -1;
    int selectedQuantity = 0;
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
        cout << "Enter the Quantity of the Item that you wanna buy. "
             << endl;
        cout << "Max quantity is: " << currentItem.item_quantity << endl;
        cin >> selectedQuantity;
        try
        {
            if (selectedQuantity > currentItem.item_quantity || selectedQuantity <= 0)
            {
                throw selectedQuantity;
            }
            else
            {
                cout << "That will be: " << currentItem.item_cost * selectedQuantity << " Rupees" << endl;
                cout << "Thank you for Purchasing!" << endl;
                updateItems(currentItem.item_cost, currentItem.item_quantity - selectedQuantity, selectedItemCode);
            }
        }
        catch (int something)
        {
            cout << "Quantity you entered is not sensible! Try again!" << endl;
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

// function to change the price of the item.
bool changePrice()
{
    int selectedItemCode = -1;
    int updatedCost = 0;
c:
    try
    {
        cout << "Please enter the code of the item that you wanna Change the Price of" << endl;
        cin >> selectedItemCode;
        if (!searchItem(selectedItemCode))
        {
            throw selectedItemCode;
        }
    l:
        cout << "Enter the Updated Price of the Item."
             << endl;
        cout << "Current Price is: " << currentItem.item_cost << endl;
        cin >> updatedCost;
        try
        {
            if (updatedCost <= 0)
            {
                throw updatedCost;
            }
            else
            {
                cout << "Done!" << endl;
                updateItems(updatedCost, currentItem.item_quantity, selectedItemCode);
            }
        }
        catch (int something)
        {
            cout << "Cost you entered is not sensible! Try again!" << endl;
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

// function to change the quantity of the item.
bool changeQuantity()
{
    int selectedItemCode = -1;
    int updatedQuantity = 0;
c:
    try
    {
        cout << "Please enter the code of the item that you wanna update" << endl;
        cin >> selectedItemCode;
        if (!searchItem(selectedItemCode))
        {
            throw selectedItemCode;
        }
    l:
        cout << "Enter the updated Quantity"
             << endl;
        cout << "Current quantity is: " << currentItem.item_quantity << endl;
        cin >> updatedQuantity;
        try
        {
            if (updatedQuantity <= 0)
            {
                throw updatedQuantity;
            }
            else
            {
                cout << "Done!" << endl;
                updateItems(currentItem.item_cost, updatedQuantity, selectedItemCode);
            }
        }
        catch (int something)
        {
            cout << "Quantity you entered is not sensible! Try again!" << endl;
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
        2. Purchase Item\n\
        3. Change Price of Item\n\
        4. Change Quantity of Item\n\
        5. View Items\n\
        6. Quit\n"
             << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertItems();
            break;
        case 2:
            displayItems();
            PurchaseItems();
            break;
        case 3:
            displayItems();
            changePrice();
            break;
        case 4:
            displayItems();
            changeQuantity();
            break;
        case 5:
            displayItems();
            break;
        case 6:
            cout << "Thanks for Visiting our store!" << endl;
            break;
        default:
            cout << "Sorry, we cant do that in this store" << endl;
            break;
        }
        itemFound = false;
    } while (choice != 6);
    return 0;
}