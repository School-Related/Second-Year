// Program for linear probing with and without replacement.

#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 10;

class Employee
{

public:
    string name;
    int id;
    int age;
    Employee()
    {
        name = "";
        id = 0;
        age = 0;
    }
    Employee(string name, int id, int age)
    {
        this->name = name;
        this->id = id;
        this->age = age;
    }
    void accept_data()
    {
        cout << "Enter name: " << endl;
        cin >> name;
        cout << "Enter id: " << endl;
        cin >> id;
        cout << "Enter age: " << endl;
        cin >> age;
    }

    void print_data()
    {
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Age: " << age << endl;
    }
};

class HashTable
{
public:
    HashTable();
    int insert_without_replacement(int key);
    int insert_with_replacement(int key);
    void print();
    int table[SIZE];
    void read_data_from_file()
    {
        // read the records from the file
        cout << "Reading data from the file. " << endl;
        Employee temp;
        fstream file("data.txt", ios::binary | ios::in);
        for (int i = 0; i < SIZE; i++)
        {
            file.read((char *)&temp, sizeof(Employee));
            cout << "Employee " << i + 1 << ": " << endl;
            temp.print_data();
            cout << endl;
        }
        // file.close();
    }

    void write_data_to_file(Employee hashed_employees[])
    {
        // Create a file in binary write mode.
        fstream file("data.txt", ios::binary | ios::out);

        // Write all the employee objects into the file in the order of the hash employee array.
        for (int i = 0; i < SIZE; i++)
        {
            cout << "Writing employee " << i + 1 << endl;
            cout << "Employee " << i + 1 << ": " << endl;
            hashed_employees[i].print_data();
            file.write((char *)&hashed_employees[i], sizeof(Employee));
        }
        // Close the file.
        file.close();
    }

private:
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
    int size;
    cout << "Enter size of table: " << endl;
    cin >> size;
    Employee employees[size];
    Employee hashed_employees[SIZE];
    HashTable hash_table;
    // Accept data for all employees
    for (int i = 0; i < size; i++)
    {
        cout << "Enter data for employee " << i + 1 << endl;
        employees[i].accept_data();
        cout << endl
             << endl;
        cout << "Employee " << i + 1 << ": " << endl;
        employees[i].print_data();
        cout << endl;
    }

    // Provide choice to users if they wanna insert with or without replacement
    int choice;
    cout << "Enter 1 to insert with replacement, 2 to insert without replacement: " << endl;
    cin >> choice;
    if (choice == 1)
    {
        // Insert data into hash table with replacement
        for (int i = 0; i < size; i++)
        {
            hash_table.insert_with_replacement(employees[i].id);
        }
    }
    else
    {
        // Insert data into hash table without replacement
        for (int i = 0; i < size; i++)
        {
            hash_table.insert_without_replacement(employees[i].id);
        }
    }

    cout << "Hash table now looks like this. " << endl;
    hash_table.print();

    cout << "Inserting data into the file. " << endl;

    // depending on the order of id in hash table, write the hashed_employee array
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (employees[j].id == hash_table.table[i])
            {
                hashed_employees[i].age = employees[j].age;
                hashed_employees[i].id = employees[j].id;
                hashed_employees[i].name = employees[j].name;
            }
        }
    }
    hash_table.write_data_to_file(hashed_employees);
    hash_table.read_data_from_file();

    return 0;
}