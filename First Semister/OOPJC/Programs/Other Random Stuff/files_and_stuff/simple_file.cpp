#include <iostream>
#include <fstream>
using namespace std;
// file modes
// ios::app : append to end of the file.
// ios::ate : go the the end of the file on opeing. 
// ios::binary : for saving structurs and stuff.
// ios::in : for input in reading only.
// ios::out: for output in writing onlyl.
// ios::nocreate : open fails if the file doesnt exist.
// ios::noreplace : open fails if the file already exists.
// ios::trunc : delete the contents of the file if ti exists.

// imp functions:
// get() : to read only a single character. will read any character.
// you gotta do ch = cin.get() or cin.get(ch) or ch = fin.get();

// getline() : read a line or basically read until you get '\n'
// getline(cin, const char[], delim_char);
// getline(fin, const char[], '\n');

// put(), exactly like get(), but for writing.

// read(), file.read((char*)&V, sizeof(V)); // when you deal with binary files or structures. 
// read(), file.write((char*)&V, sizeof(V)); // same, when we are talking binary or structures. 

// the extraction and insertion operator:
// >> to read data like fin>>ch;
// << to write data into file fout<<ch;

void create_simple_file()
{
    ifstream fin;
    ofstream fout;
    fstream f;
    f.open("Ramesh.txt", ios::out); // will still not create ramesh, even if you write to it. 
    fin.open("Suresh.txt", ios::out); // wont create suresh
    fout.open("binary_thing.bin", ios::binary | ios::out); // will create it immediately. 
    fout.open("Rajesh2.txt"); // will immediately create rajesh2.txt

    fout << "hi"; // would write to rajesh, not binary_thing.bin
    f << "hi";
    f.close();
    fin.close();
    fout.close();
}

int main()
{
    create_simple_file();
    return 0;
}