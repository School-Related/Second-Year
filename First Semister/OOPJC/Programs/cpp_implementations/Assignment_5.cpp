#include <iostream>
#include <fstream>

// file modes
// ios::app : append to end of the file.
// ios::binary : for saving structurs and stuff.
// ios::in : for input in reading only.
// ios::out: for output in writing onlyl.
// ios:: nocreate : open fails if the file doesnt exist.
// ios::noreplace : open fails if the file already exists.
// ios::trunc : delete the contents of the file if ti exists.

// using namespace std;
// int main()
// {
//     char name[30];
//     float cost;
//     ofstream outf("Product.txt");
//     cout << "Enter Product Name" << endl;
//     cin >> name;
//     outf << name << "\n";

//     cout << "Enter Product Cost" << endl;
//     cin >> cost;
//     outf << cost << "\n";
//     outf.close();

//     ifstream inf("Product.txt");
//     inf >> name;
//     inf >> cost;
//     cout << "\n";
//     cout << "Product Name: " << name << endl;
//     cout << "roduct Cost: " << cost << endl;
//     inf.close();
//     return 0;
// }

using namespace std;
int main()
{
    ofstream fout;
    fout.open("country.txt");
    fout << "India \n";
    fout << "United states of America \n";
    fout << "United Kingdom \n";
    fout.close();
    fout.open("capital.txt");
    fout << "New Delhi \n";
    fout << "Washington\n";
    fout << "London\n";
    fout.close();
    int N = 50;
    char line[N];
    ifstream fin;
    fin.open("country.txt");
    cout << "contents of country file \n\n";
    while (fin)
    {
        fin.getline(line, N);
        cout << line << endl;
    }
    fin.close();
    fin.open("capital.txt");
    cout << "\ncontents of capital file\n\n";
    while (fin)
    {
        fin.getline(line, N);
        cout << line << endl;
    }
    fin.close();
    return 0;
}