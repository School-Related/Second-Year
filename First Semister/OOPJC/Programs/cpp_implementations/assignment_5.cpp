#include <iostream>
#include <list>
using namespace std;

int main()
{
    cout << "Welcome to McRonalds" << endl;
    list<int> myList = {1, 2, 3};
    myList.push_back(6);
    myList.push_front(4);
    // list<int> iterator itr;
    // itr = find(myList.begin(), myList.end(), 2);

    return 0;
}