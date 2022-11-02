// #include <iostream>
// #include <fstream>

// // file modes
// // ios::app : append to end of the file.
// // ios::binary : for saving structurs and stuff.
// // ios::in : for input in reading only.
// // ios::out: for output in writing onlyl.
// // ios:: nocreate : open fails if the file doesnt exist.
// // ios::noreplace : open fails if the file already exists.
// // ios::trunc : delete the contents of the file if ti exists.

// // using namespace std;
// // int main()
// // {
// //     char name[30];
// //     float cost;
// //     ofstream outf("Product.txt");
// //     cout << "Enter Product Name" << endl;
// //     cin >> name;
// //     outf << name << "\n";

// //     cout << "Enter Product Cost" << endl;
// //     cin >> cost;
// //     outf << cost << "\n";
// //     outf.close();

// //     ifstream inf("Product.txt");
// //     inf >> name;
// //     inf >> cost;
// //     cout << "\n";
// //     cout << "Product Name: " << name << endl;
// //     cout << "roduct Cost: " << cost << endl;
// //     inf.close();
// //     return 0;
// // }

// using namespace std;
// int main()
// {
//     ofstream fout;
//     fout.open("country.txt");
//     fout << "India \n";
//     fout << "United states of America \n";
//     fout << "United Kingdom \n";
//     fout.close();
//     fout.open("capital.txt");
//     fout << "New Delhi \n";
//     fout << "Washington\n";
//     fout << "London\n";
//     fout.close();
//     int N = 50;
//     char line[N];
//     ifstream fin;
//     fin.open("country.txt");
//     cout << "contents of country file \n\n";
//     while (fin)
//     {
//         fin.getline(line, N);
//         cout << line << endl;
//     }
//     fin.close();
// //     fin.open("capital.txt");
// //     cout << "\ncontents of capital file\n\n";
// //     while (fin)
// //     {
// //         fin.getline(line, N);
// //         cout << line << endl;
// //     }
// //     fin.close();
// //     return 0;
// // }

// #include <iostream>
// #include <fstream>

// using namespace std;

// class store
// {
//     string name;
//     int code;
//     float cost;

// public:
//     void read_data()
//     {
//         cout << "Enter book name " << endl;
//         cin >> name;
//         cout << "Enter book code: " << endl;
//         cin >> code;
//         cout << "Enter book cost: " << endl;
//         cin >> cost;
//     }

//     void display_data()
//     {
//         cout << name << "\t" << code << "\t" << cost << endl;
//     }
// };

// int main()
// {
//     store product[3];
//     fstream file;
//     file.open("book.txt", ios::in | ios::out);

//     cout << "Enter detaisl of 3 Books" << endl;

//     for (int i = 0; i < 3; i++)
//     {
//         product[i].read_data();
//         file.write((char *)&product[i], sizeof(product[i]));
//         // file.seekg(sizeof(product[i]));
//     }
//     file.seekg(0);
//     cout << endl
//          << "Book Details are: " << endl;
//     // store s[3];
//     store s;
//     for (int i = 0; i < 3; i++)
//     {
//         file.read((char *)&s, sizeof(s));
//         s.display_data();
//     }
//     file.close();

//     return 0;
// }


#include<iostream>
#include<fstream>
using namespace std;


int main()
{
    fstream file;
    file.open("test.txt");
    if(!file.is_open())
    {
        cout << "Cannot Open file !" << endl;
    }
    file << "This is the first line" << endl;
    file << "This is the second line" << endl;
    file.seekg(ios::beg);
    for (int i = 0; i < 5; i++)
    {
        // char a = file.get();
        cout << (char)file.get() << endl;
        // cout << file.tellg();
    }

    char next = file.get();
    cout << "The Next character is: " << (char)next;
    cout << endl;
    file.seekg(ios::beg);
    char *str = new char[50];
    file.getline(str, 50);
    cout<<str<<endl;
    file.ignore();
    cout << "Peek = " << (char)file.peek() << endl;
    cout << "Current position is: " << file.tellg() << endl;
    file.close();
    return 0;
}