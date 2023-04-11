// Program for linear probing with and without replacement.

#include <iostream>

using namespace std;

const int SIZE = 10;

class HashTable
{
public:
    HashTable();
    int insert_without_replacement(int key);
    int insert_with_replacement(int key);
    void print();

private:
    int table[SIZE];
    int hash(int key);
};

HashTable::HashTable()
{
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int HashTable::hash(int key)
{
    return key % SIZE;
}

int HashTable::insert_without_replacement(int key)
{
    int index = hash(key);
    if (table[index] == -1)
        table[index] = key;
    else
    {
        int i = 1;
        while (table[(index + i) % SIZE] != -1)
        {
            i++;
            if (i == SIZE)
            {
                cout << "Table is full. " << endl;
                return 1;
            }
        }
        table[(index + i) % SIZE] = key;
    }
    return 0;
}

int HashTable::insert_with_replacement(int key)
{
    int index = hash(key);

    // there is no value there.
    if (table[index] == -1)
        table[index] = key;
    // the value that is already there, belongs there, then check, and then find another empty slot and insert there.
    else if (hash(table[index]) == index)
    {
        int i = 1;
        while (table[(index + i) % SIZE] != -1)
        {
            i++;
            if (i == SIZE)
            {
                cout << "Table is full. " << endl;
                return 1;
            }
        }
        table[(index + i) % SIZE] = key;
    }
    // the value that is already there, does not belong there, then replace it with the new value, and push the existing value down.
    else
    {
        // find empty slot
        int i = 1;
        while (table[(index + i) % SIZE] != -1)
        {
            i++;
            if (i == SIZE)
            {
                cout << "Table is full. " << endl;
                return 1;
            }
        }

        int temp = table[index]; // current value that doesnt belong there.
        table[index] = key;
        table[(index + i) % SIZE] = temp;
    }
    return 0;
}

void HashTable::print()
{
    for (int i = 0; i < SIZE; i++)
        cout << i << ":" << table[i] << " " << endl;
    cout << endl;
}

int main()
{
    HashTable table;
    int key;

    cout << "Welcome to ADS Assignment 8, hashign with linear probing. " << endl;
    cout << "What do you want to do? " << endl;
    cout << "1. Insert without replacement. " << endl;
    cout << "2. Insert with replacement. " << endl;
    cout << "3. Exit. " << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "You chose to insert without replacement. " << endl;
        cout << "Enter the keys to insert. " << endl;
        while (cin >> key)
        {
            if (table.insert_without_replacement(key) != 1)
            {
                cout << "The table is now: " << endl;
                table.print();
            }
            else
                break;
        }
        break;
    case 2:
        cout << "You chose to insert with replacement. " << endl;
        cout << "Enter the keys to insert. " << endl;
        while (cin >> key)
        {
            if (table.insert_with_replacement(key) != 1)
            {
                cout << "The table is now: " << endl;
                table.print();
            }
            else
                break;
        }
        break;
    case 3:
        cout << "You chose to exit. " << endl;
        return 0;
    default:
        cout << "Invalid choice. " << endl;
        return 0;
    }
    return 0;
}